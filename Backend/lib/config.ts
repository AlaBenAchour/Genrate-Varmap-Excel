// Centralized configuration for the application
export const config = {
    // MinIO Configuration
    minio: {
        endpoint: process.env.MINIO_ENDPOINT || 'localhost',
        port: parseInt(process.env.MINIO_PORT || '9001'),
        useSSL: process.env.MINIO_USE_SSL === 'true',
        accessKey: process.env.MINIO_ACCESS_KEY || '',
        secretKey: process.env.MINIO_SECRET_KEY || '',
        bucket: process.env.MINIO_BUCKET || 'app-store',
        
    },


    // Database Configuration
    database: {
        url: process.env.DATABASE_URL,
    },
}

// Helper functions
export const getMinioUrl = () => {
    const protocol = config.minio.useSSL ? 'https' : 'http'
    return `${protocol}://${config.minio.endpoint}:${config.minio.port}`
}

export const getMinioConsoleUrl = () => {
    const protocol = config.minio.useSSL ? 'https' : 'http'
    return `${protocol}://${config.minio.endpoint}:${config.minio.port}`
}

export const getPublicFileUrl = (bucketName: string, objectKey: string) => {
    const protocol = config.minio.useSSL ? 'https' : 'http'
    return `${protocol}://${config.minio.endpoint}:${config.minio.port}/${bucketName}/${objectKey}`
}

// Validation functions
export const validateMinioConfig = () => {
    const required = ['endpoint', 'port', 'accessKey', 'secretKey']
    const missing = required.filter(key => !config.minio[key as keyof typeof config.minio])

    if (missing.length > 0) {
        throw new Error(`Missing required MinIO configuration: ${missing.join(', ')}`)
    }

    // Additional validation for access keys
    if (!config.minio.accessKey || config.minio.accessKey === '') {
        throw new Error('MINIO_ACCESS_KEY is required. Please generate access keys from MinIO Console.')
    }

    if (!config.minio.secretKey || config.minio.secretKey === '') {
        throw new Error('MINIO_SECRET_KEY is required. Please generate access keys from MinIO Console.')
    }

    return true
}


