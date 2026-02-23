import { BucketItemStat } from 'minio'
import type internal from 'stream'
import { MinioClient } from './client'
import { config, getPublicFileUrl } from './config'


// Initialize MinIO client (keeping for backward compatibility)
const minioClient = MinioClient

// Bucket configurations
export const BUCKETS = {
    APP_STORE: config.minio.bucket,

} as const

export type BucketType = keyof typeof BUCKETS
export type FileVisibility = 'app-store'

// File metadata interface
export interface FileMetadata {
    id: string
    originalName: string
    fileName: string
    mimeType: string
    size: number
    bucket: string
    objectKey: string
    visibility: FileVisibility
    folder?: string
    url?: string
    createdAt: Date
    updatedAt: Date
}

// Upload options interface
export interface UploadOptions {
    visibility?: FileVisibility
    folder?: string
    fileName?: string
    metadata?: Record<string, string>
    contentType?: string
}

// ===========================================
// BUCKET MANAGEMENT
// ===========================================

/**
 * Check if a bucket exists
 */
export async function bucketExists(bucketName: string): Promise<boolean> {
    try {
        return await minioClient.bucketExists(bucketName)
    } catch (error) {
        console.error(`Error checking bucket existence: ${bucketName}`, error)
        // If it's a connection error, throw it to be handled upstream
        const errorMessage = error instanceof Error ? error.message : String(error)
        if (errorMessage.includes('API port') || errorMessage.includes('InvalidArgument')) {
            throw new Error(`MinIO connection failed. Please ensure MinIO is running on ${config.minio.endpoint}:${config.minio.port}. Error: ${errorMessage}`)
        }
        return false
    }
}

/**
 * Create a bucket with appropriate policies
 */
export async function createBucket(
    bucketName: string,
    isPublic: boolean = false,
    region: string = 'us-east-1'
): Promise<void> {
    try {
        const exists = await bucketExists(bucketName)
        if (exists) {
            console.log(`Bucket "${bucketName}" already exists`)
            return
        }

        await minioClient.makeBucket(bucketName, region)
        console.log(`Bucket "${bucketName}" created successfully`)

        // Set bucket policy based on visibility
        if (isPublic) {
            await setPublicBucketPolicy(bucketName)
        } 
    } catch (error) {
        console.error(`Error creating bucket: ${bucketName}`, error)
        throw new Error(`Failed to create bucket: ${bucketName}`)
    }
}


// ===========================================
// BUCKET POLICIES
// ===========================================

/**
 * Set secure public read policy for a bucket with referrer protection
 */
async function setPublicBucketPolicy(bucketName: string): Promise<void> {
    const websiteDomain = process.env.FRONTEND_APP_DOMAIN || 'app.localhost'

    const policy = {
        Version: '2012-10-17',
        Statement: [
            {
                Sid: 'AllowPublicReadWithReferrerCheck',
                Effect: 'Allow',
                Principal: { AWS: ['*'] },
                Action: ['s3:GetObject'],
                Resource: [`arn:aws:s3:::${bucketName}/*`],
                Condition: {
                    StringLike: {
                        'aws:Referer': [
                            `*${websiteDomain}*`,
                            `*localhost*`, // Allow localhost for development
                        ]
                    }
                }
            },
            {
                Sid: 'AllowDirectAccessFromWebsite',
                Effect: 'Allow',
                Principal: { AWS: ['*'] },
                Action: ['s3:GetObject'],
                Resource: [`arn:aws:s3:::${bucketName}/*`],
                Condition: {
                    StringEquals: {
                        's3:ExistingObjectTag/source': 'website'
                    }
                }
            }
        ],
    }

    try {
        await minioClient.setBucketPolicy(bucketName, JSON.stringify(policy))
        console.log(`Secure public policy set for bucket: ${bucketName}`)
    } catch (error) {
        console.error(`Error setting public policy for bucket: ${bucketName}`, error)
    }
}



// ===========================================
// FILE UPLOAD
// ===========================================


// ===========================================
// FILE DOWNLOAD & ACCESS
// ===========================================




/**
 * Get file metadata/stats
 */
export async function getFileStats(bucketName: string, objectKey: string): Promise<BucketItemStat> {
    try {
        return await minioClient.statObject(bucketName, objectKey)
    } catch (error) {
        console.error('Error getting file stats', error)
        throw new Error('Failed to get file stats')
    }
}

// ===========================================
// FILE MANAGEMENT
// ===========================================

/**
 * Delete a file from MinIO
 */
export async function deleteFile(bucketName: string, objectKey: string): Promise<void> {
    try {
        await minioClient.removeObject(bucketName, objectKey)
        console.log(`File deleted successfully: ${objectKey}`)
    } catch (error) {
        console.error('Error deleting file', error)
        throw new Error('Failed to delete file')
    }
}



// ===========================================
// FOLDER MANAGEMENT
// ===========================================

/**
 * List files in a folder (prefix)
 */
export async function listFilesInFolder(
    bucketName: string,
    folderPrefix: string = '',
    recursive: boolean = false
): Promise<any[]> {
    try {
        const stream = minioClient.listObjects(bucketName, folderPrefix, recursive)
        const objects: any[] = []

        return new Promise((resolve, reject) => {
            stream.on('data', (obj) => objects.push(obj))
            stream.on('end', () => resolve(objects))
            stream.on('error', reject)
        })
    } catch (error) {
        console.error('Error listing files in folder', error)
        throw new Error('Failed to list files in folder')
    }
}

/**
 * Create a folder (by uploading an empty object)
 */
export async function createFolder(bucketName: string, folderName: string): Promise<void> {
    try {
        const folderKey = folderName.endsWith('/') ? folderName : `${folderName}/`
        const emptyBuffer = Buffer.alloc(0)

        await minioClient.putObject(bucketName, folderKey, emptyBuffer, 0)
        console.log(`Folder created: ${folderKey}`)
    } catch (error) {
        console.error('Error creating folder', error)
        throw new Error('Failed to create folder')
    }
}

// Folder deletion removed for security - delete files individually instead

// ===========================================
// UTILITY FUNCTIONS
// ===========================================

// Bulk deletion removed for security

/**
 * Generate presigned upload URL
 */
export async function generatePresignedUploadUrl(
    bucketName: string,
    objectKey: string,
    expiry: number = 3600
): Promise<string> {
    try {
        return await minioClient.presignedPutObject(bucketName, objectKey, expiry)
    } catch (error) {
        console.error('Error generating presigned upload URL', error)
        throw new Error('Failed to generate presigned upload URL')
    }
}

/**
 * Get bucket storage usage statistics
 */
export async function getBucketStats(bucketName: string): Promise<{
    objectCount: number
    totalSize: number
    folders: string[]
}> {
    try {
        const objects = await listFilesInFolder(bucketName, '', true)

        const totalSize = objects.reduce((sum, obj) => sum + (obj.size || 0), 0)
        const folders = [...new Set(
            objects
                .map(obj => obj.name?.split('/')[0])
                .filter(folder => folder !== '' && folder !== undefined)
        )]

        return {
            objectCount: objects.length,
            totalSize,
            folders
        }
    } catch (error) {
        console.error('Error getting bucket stats', error)
        throw new Error('Failed to get bucket stats')
    }
}


// ===========================================
// COMPATIBILITY FUNCTIONS (as requested)
// ===========================================

/**
 * Create bucket if it doesn't exist
 */
export async function createBucketIfNotExists(bucketName: string) {
    const bucketExists = await MinioClient.bucketExists(bucketName);
    if (!bucketExists) {
        await MinioClient.makeBucket(bucketName);
    }
}

/**
 * Save file in bucket with duplicate check
 */
export async function saveFileInBucket({
    bucketName,
    fileName,
    file,
}: {
    bucketName: string;
    fileName: string;
    file: Buffer | internal.Readable;
}) {
    // Create bucket if it doesn't exist
    await createBucketIfNotExists(bucketName);

    // check if file exists
    const fileExists = await checkFileExistsInBucket({
        bucketName,
        fileName,
    });

    if (fileExists) {
        throw new Error("File already exists");
    }

    // Upload image to S3 bucket
    await MinioClient.putObject(bucketName, fileName, file);
}

/**
 * Check if file exists in bucket
 */
export async function checkFileExistsInBucket({
    bucketName,
    fileName,
}: {
    bucketName: string;
    fileName: string;
}) {
    try {
        await MinioClient.statObject(bucketName, fileName);
    } catch (error) {
        return false;
    }
    return true;
}

/**
 * Get file from bucket
 */
export async function getFileFromBucket({
    bucketName,
    fileName,
}: {
    bucketName: string;
    fileName: string;
}) {
    try {
        await MinioClient.statObject(bucketName, fileName);
    } catch (error) {
        console.error(error);
        return null;
    }
    return await MinioClient.getObject(bucketName, fileName);
}

/**
 * Delete file from bucket
 */
export async function deleteFileFromBucket({
    bucketName,
    fileName,
}: {
    bucketName: string;
    fileName: string;
}) {
    try {
        await MinioClient.removeObject(bucketName, fileName);
    } catch (error) {
        console.error(error);
        return false;
    }
    return true;
}






