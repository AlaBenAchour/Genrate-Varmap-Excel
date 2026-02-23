import { useState } from 'react';

interface UploadedFile {
  id: string;
  filename: string;
  originalName: string;
  url: string;
  size: number;
  mimeType: string;
  uploadedAt: string;
}

interface UseFileUploadOptions {
  maxSize?: number;
  onSuccess?: (file: UploadedFile) => void;
  onError?: (error: string) => void;
}

interface UploadMetadata {
  fileName?: string;
  date?: string;
}

export function useFileUploadModal(options: UseFileUploadOptions = {}) {
  const { maxSize = 10 * 1024 * 1024, onSuccess, onError } = options;
  const [uploading, setUploading] = useState(false);
  const [progress, setProgress] = useState(0);
  const [error, setError] = useState<string | null>(null);

  const clearError = () => setError(null);

  const uploadFile = async (file: File, metadata?: UploadMetadata) => {
    if (file.size > maxSize) {
      const errorMsg = `File size exceeds maximum allowed size of ${(maxSize / 1024 / 1024).toFixed(1)}MB`;
      setError(errorMsg);
      onError?.(errorMsg);
      return null;
    }

    setUploading(true);
    setProgress(0);
    setError(null);

    try {
      const formData = new FormData();
      formData.append('file', file);
      
      if (metadata?.fileName) {
        formData.append('fileName', metadata.fileName);
      }
      if (metadata?.date) {
        formData.append('date', metadata.date);
      }

      // Simulate progress
      const progressInterval = setInterval(() => {
        setProgress(prev => {
          if (prev >= 90) {
            clearInterval(progressInterval);
            return 90;
          }
          return prev + 10;
        });
      }, 200);

      // Upload file and generate Excel
      const response = await fetch('http://localhost:5000/api/generate-excel', {
        method: 'POST',
        body: formData,
      });

      clearInterval(progressInterval);

      if (!response.ok) {
        throw new Error('Upload failed');
      }

      const result = await response.json();
      
      setProgress(100);

      // Create uploaded file object for the Excel file
      const uploadedFile: UploadedFile = {
        id: result.excelFile,
        filename: result.excelFile,
        originalName: result.excelFile,
        url: `http://localhost:5000/files/${result.excelFile}`,
        size: 0, // Size will be determined by the file
        mimeType: 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
        uploadedAt: new Date().toISOString(),
      };

      onSuccess?.(uploadedFile);
      
      setTimeout(() => {
        setUploading(false);
        setProgress(0);
      }, 500);

      return uploadedFile;
    } catch (err) {
      const errorMsg = err instanceof Error ? err.message : 'Upload failed';
      setError(errorMsg);
      onError?.(errorMsg);
      setUploading(false);
      setProgress(0);
      return null;
    }
  };

  const uploadMultipleFiles = async (files: File[]) => {
    const results = [];
    for (const file of files) {
      const result = await uploadFile(file);
      if (result) {
        results.push(result);
      }
    }
    return results;
  };

  return {
    uploading,
    progress,
    error,
    uploadFile,
    uploadMultipleFiles,
    clearError,
  };
}
