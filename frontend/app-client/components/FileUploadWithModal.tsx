"use client";

import { useRef, useState } from "react";
import { useFileUpload } from "@/hooks/useFileUpload";
import { useFileUploadModal } from "@/hooks/useFileUploadModal";

interface UploadedFile {
  id: string;
  filename: string;
  originalName: string;
  url: string;
  size: number;
  mimeType: string;
  uploadedAt: string;
}

interface FileUploadProps {
  onUploadComplete?: (file: UploadedFile) => void;
  accept?: string;
  maxSize?: number; // in bytes
  multiple?: boolean;
}

export default function FileUploadWithModal({
  onUploadComplete,
  // accept = '*/*',
  accept = ".h",
  maxSize = 10 * 1024 * 1024, // 10MB default
  multiple = false,
}: FileUploadProps) {
  const fileInputRef = useRef<HTMLInputElement>(null);

  const [showModal, setShowModal] = useState(false);
  const [selectedFile, setSelectedFile] = useState<File | null>(null);
  const [fileName, setFileName] = useState("");
  const [date, setDate] = useState("");
  
  const {
    uploading,
    progress,
    error,
    uploadFile,
  //  uploadMultipleFiles,
    clearError,
  } = useFileUploadModal({
    maxSize,
    onSuccess: onUploadComplete,
    onError: (error) => console.error("Upload error:", error),
  });
  const isValidHFile = (file: File) => {
    return file.name.toLowerCase().endsWith(".h");
  };

  //   const handleFileSelect = async (files: FileList | null) => {
  //     if (!files) return;

  //     if (multiple) {
  //       await uploadMultipleFiles(Array.from(files));
  //     } else {
  //       await uploadFile(files[0]);
  //     }

  //     // Reset input
  //     if (fileInputRef.current) {
  //       fileInputRef.current.value = "";
  //     }
  //   };
  const handleFileSelect = async (files: FileList | null) => {
    // if (!files) return;

    // const fileArray = Array.from(files);
     if (!files || files.length === 0) return;

    const file = files[0];

    // Validate all files
    // for (const file of fileArray) {
    //   if (!isValidHFile(file)) {
    //     alert("Only .h files are allowed");
    //     return;
    //   }
    // }
    if (!isValidHFile(file)) {
      alert("Only .h files are allowed");
      return;
    }
    // if (multiple) {
    //   await uploadMultipleFiles(fileArray);
    // } else {
    //   await uploadFile(fileArray[0]);
    // }

    // if (fileInputRef.current) {
    //   fileInputRef.current.value = "";
    // }

     // Store the file and show modal
    setSelectedFile(file);
    setShowModal(true);
  };
  const handleModalSubmit = async (e: React.FormEvent) => {
    e.preventDefault();

    if (!selectedFile) return;

    // Close modal
    setShowModal(false);

    // Upload file with metadata
    await uploadFile(selectedFile, { fileName, date });

    // Reset form
    setFileName("");
    setDate("");
    setSelectedFile(null);

    if (fileInputRef.current) {
      fileInputRef.current.value = "";
    }
  };

  const handleModalClose = () => {
    setShowModal(false);
    setFileName("");
    setDate("");
    setSelectedFile(null);
    if (fileInputRef.current) {
      fileInputRef.current.value = "";
    }
  };
  const handleDrop = (e: React.DragEvent) => {
    e.preventDefault();
    handleFileSelect(e.dataTransfer.files);
  };

  const handleDragOver = (e: React.DragEvent) => {
    e.preventDefault();
  };

  const handleDragLeave = (e: React.DragEvent) => {
    e.preventDefault();
  };

  return (
     <>
    <div className="w-full max-w-md mx-auto">
      <div
        className={`
          border-2 border-dashed rounded-lg p-8 text-center cursor-pointer transition-colors
          ${uploading ? "opacity-50 pointer-events-none" : "hover:border-blue-400"}
          border-gray-300
        `}
        onDrop={handleDrop}
        onDragOver={handleDragOver}
        onDragLeave={handleDragLeave}
        onClick={() => fileInputRef.current?.click()}
      >
        <input
          ref={fileInputRef}
          type="file"
          accept={accept}
          multiple={multiple}
          className="hidden"
          onChange={(e) => handleFileSelect(e.target.files)}
          disabled={uploading}
        />

        {uploading ? (
          <div className="flex flex-col items-center">
            <div className="relative w-16 h-16 mb-4">
              <div className="absolute inset-0 rounded-full border-4 border-gray-200"></div>
              <div
                className="absolute inset-0 rounded-full border-4 border-blue-500 border-t-transparent"
                style={{
                  transform: `rotate(${progress * 3.6}deg)`,
                }}
              ></div>
              <div className="absolute inset-0 flex items-center justify-center">
                <span className="text-sm font-medium">{progress}%</span>
              </div>
            </div>
            <p className="text-gray-600">Uploading...</p>
          </div>
        ) : (
          <div className="flex flex-col items-center">
            <svg
              className="h-12 w-12 text-gray-400 mb-4"
              fill="none"
              strokeLinecap="round"
              strokeLinejoin="round"
              strokeWidth="2"
              viewBox="0 0 24 24"
              stroke="currentColor"
            >
              <path d="M7 16a4 4 0 01-.88-7.903A5 5 0 1115.9 6L16 6a5 5 0 011 9.9M15 13l-3-3m0 0l-3 3m3-3v12" />
            </svg>
            <p className="text-gray-600 mb-2">
              {multiple
                ? "Drop files here or click to select"
                : "Drop file here or click to select"}
            </p>
            <p className="text-sm text-gray-400">
              Max size: {(maxSize / 1024 / 1024).toFixed(1)}MB
            </p>
          </div>
        )}
      </div>

      {error && (
        <div className="mt-4 p-3 bg-red-100 border border-red-400 text-red-700 rounded flex justify-between items-center">
          <span>{error}</span>
          <button
            onClick={clearError}
            className="text-red-800 hover:text-red-900 underline text-sm"
          >
            Dismiss
          </button>
        </div>
      )}
    </div>
     {/* Modal */}
      {showModal && (
        <div
          className="fixed inset-0 z-50 flex items-center justify-center bg-black/50 backdrop-blur-md overflow-x-hidden"
          onClick={handleModalClose}
        >
          <div
            onClick={(e) => e.stopPropagation()}
            className="relative bg-white rounded-lg shadow w-full max-w-md px-6 sm:px-10"
          >
            <button
              type="button"
              className="absolute top-3 right-2.5 text-gray-400 bg-transparent hover:bg-gray-200 hover:text-gray-900 rounded-lg text-sm p-1.5 ml-auto inline-flex items-center"
              onClick={handleModalClose}
            >
              <svg
                aria-hidden="true"
                className="w-5 h-5"
                fill="#c6c7c7"
                viewBox="0 0 20 20"
                xmlns="http://www.w3.org/2000/svg"
              >
                <path
                  fillRule="evenodd"
                  d="M4.293 4.293a1 1 0 011.414 0L10 8.586l4.293-4.293a1 1 0 111.414 1.414L11.414 10l4.293 4.293a1 1 0 01-1.414 1.414L10 11.414l-4.293 4.293a1 1 0 01-1.414-1.414L8.586 10 4.293 5.707a1 1 0 010-1.414z"
                  clipRule="evenodd"
                ></path>
              </svg>
              <span className="sr-only">Close popup</span>
            </button>

            <div className="p-5">
              <div className="text-center">
                <p className="mb-3 text-2xl font-semibold leading-5 text-slate-900">
                  Upload File Information
                </p>
                <p className="mt-2 text-sm leading-4 text-slate-600">
                  Enter file name and date for {selectedFile?.name}
                </p>
              </div>

              <form className="w-full gap-2 py-6" onSubmit={handleModalSubmit}>
                <label htmlFor="fileName" className="sr-only">
                  Name Excel
                </label>
                <input
                  id="fileName"
                  value={fileName}
                  onChange={(e) => setFileName(e.target.value)}
                  name="text"
                  type="text"
                  autoComplete="off"
                  required
                  className="block w-full rounded-lg border border-gray-300 px-3 py-2 shadow-sm outline-none placeholder:text-gray-400 focus:ring-2 focus:ring-black focus:ring-offset-1"
                  placeholder="Name Excel"
                />
                <label htmlFor="date" className="sr-only">
                  Date
                </label>
                <input
                  id="date"
                  value={date}
                  onChange={(e) => setDate(e.target.value)}
                  name="date"
                  type="date"
                  autoComplete="off"
                  required
                  className="mt-2 block w-full rounded-lg border border-gray-300 px-3 py-2 shadow-sm outline-none placeholder:text-gray-400 focus:ring-2 focus:ring-black focus:ring-offset-1"
                  placeholder="Date"
                />
                <button
                  type="submit"
                  className="inline-flex mt-4 w-full items-center justify-center rounded-lg bg-black p-2 py-3 text-sm font-medium text-white outline-none focus:ring-2 focus:ring-black focus:ring-offset-1 disabled:bg-gray-400"
                >
                  Upload and Generate
                </button>
              </form>
            </div>
          </div>
        </div>
      )}
      </>
  );
}
