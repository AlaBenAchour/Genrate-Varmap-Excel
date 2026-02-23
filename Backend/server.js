require("dotenv").config();

const express = require("express");
const cors = require("cors");
const fs = require("fs");
const path = require("path");
const multer = require("multer");
const ExcelJS = require("exceljs");
const Minio = require("minio");
const { PrismaClient } = require("@prisma/client");


const prisma = new PrismaClient();

const app = express();
app.use(cors());
app.use(express.json());

// MinIO Configuration (aligned with TypeScript config)
const minioConfig = {
  endPoint: process.env.MINIO_ENDPOINT || "localhost",
  port: parseInt(process.env.MINIO_PORT || "9001"), // Changed from 9000 to 9001
  useSSL: process.env.MINIO_USE_SSL === "true",
  accessKey: process.env.MINIO_ACCESS_KEY || "",
  secretKey: process.env.MINIO_SECRET_KEY || "",
};
// Validate MinIO configuration
if (!minioConfig.accessKey || !minioConfig.secretKey) {
  console.error("ERROR: MINIO_ACCESS_KEY and MINIO_SECRET_KEY are required!");
  console.error(
    "Please set these environment variables before starting the server.",
  );
  process.exit(1);
}

// MinIO client initialization
const minioClient = new Minio.Client(minioConfig);

// Bucket name (aligned with TypeScript config)
const BUCKET_NAME = process.env.MINIO_BUCKET || "app-store"; // Changed from "app-files"
// Initialize MinIO bucket
async function initializeBucket() {
  try {
    const exists = await minioClient.bucketExists(BUCKET_NAME);
    if (!exists) {
      await minioClient.makeBucket(BUCKET_NAME, "us-east-1");
      console.log(`✓ Bucket ${BUCKET_NAME} created successfully`);
    } else {
      console.log(`✓ Bucket ${BUCKET_NAME} already exists`);
    }
  } catch (error) {
    console.error("✗ Error initializing MinIO bucket:", error.message);
    if (
      error.message.includes("API port") ||
      error.message.includes("InvalidArgument")
    ) {
      console.error(
        `\nPlease ensure MinIO is running on ${minioConfig.endPoint}:${minioConfig.port}`,
      );
    }
    process.exit(1);
  }
}
// Initialize bucket on startup
initializeBucket();

// Fonction pour mettre la première lettre de chaque mot en majuscule
function capitalizeWords(str) {
  return str.replace(/\b\w/g, (char) => char.toUpperCase());
}
// Fonction pour nettoyer le nom
function cleanName(name, caseNumber = null) {
  let cleaned = name.split("(")[0]; // enlever paramètres
  cleaned = cleaned.replace(/^(FV_|FNV_|RV_|RNV_|TMR_)/, ""); // enlever préfixe
  cleaned = cleaned.toLowerCase();
  cleaned = cleaned.replace(/_/g, " "); // _ → espace
  cleaned = cleaned.replace(/\s+/g, " ").trim(); // supprimer espaces multiples
  cleaned = capitalizeWords(cleaned); // chaque mot commence par majuscule
  if (caseNumber !== null) {
    cleaned += ` (${caseNumber + 1})`; // ajouter numéro de case (1-based)
  }
  return cleaned;
}
//const multer = require("multer");

// Config stockage avec multer (temporaire)
const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    const uploadDir = "temp/";
    if (!fs.existsSync(uploadDir)) {
      fs.mkdirSync(uploadDir, { recursive: true });
    }
    cb(null, uploadDir);
  },
  filename: (req, file, cb) => {
    cb(null, Date.now() + "-" + file.originalname);
  },
});
// const storage = multer.diskStorage({
//   destination: (req, file, cb) => {
//     cb(null, "files/");
//   },
//   filename: (req, file, cb) => {
//     cb(null, Date.now() + "-" + file.originalname);
//   },
// });

const upload = multer({ storage });

// Helper function to upload file to MinIO
async function uploadToMinio(filePath, fileName) {
  try {
    const fileStream = fs.createReadStream(filePath);
    const fileStat = fs.statSync(filePath);

    await minioClient.putObject(
      BUCKET_NAME,
      fileName,
      fileStream,
      fileStat.size,
    );

    console.log(`✓ File ${fileName} uploaded to MinIO successfully`);
    return fileName;
  } catch (error) {
    console.error("✗ Error uploading to MinIO:", error.message);
    throw error;
  }
}
// Helper function to get file from MinIO as buffer
async function getFileFromMinio(fileName) {
  try {
    return new Promise((resolve, reject) => {
      const chunks = [];
      minioClient.getObject(BUCKET_NAME, fileName, (err, dataStream) => {
        if (err) {
          return reject(err);
        }
        dataStream.on("data", (chunk) => {
          chunks.push(chunk);
        });
        dataStream.on("end", () => {
          resolve(Buffer.concat(chunks));
        });
        dataStream.on("error", (err) => {
          reject(err);
        });
      });
    });
  } catch (error) {
    console.error("✗ Error getting file from MinIO:", error.message);
    throw error;
  }
}
// Lire le fichier .h et transformer en JSON avec calcul des macros
// app.get("/api/data", (req, res) => {
//   const filePath = path.join(__dirname, "files", "ventilation.h");
// app.post("/api/data", upload.single("file"), (req, res) => {
//   const filePath = req.file.path; // le fichier uploadé
//   fs.readFile(filePath, "utf8", (err, content) => {
//     if (err) {
//       return res.status(500).json({ error: "Erreur lecture fichier" });
//     }

//     const lines = content.split("\n");

//     const constants = {};
//     const data = [];

//     //  Lire toutes les constantes
//     lines.forEach((line) => {
//       line = line.trim();
//       const constMatch = line.match(/^#define\s+(\w+)\s+(\d+)/);
//       if (constMatch) {
//         const name = constMatch[1];
//         const value = parseInt(constMatch[2]);
//         constants[name] = value;
//       }
//     });

//     // Lire les macros avec paramètres
//     lines.forEach((line) => {
//       line = line.trim();
//       if (line.startsWith("#define")) {
//         const parts = line.split(/\s+/);
//         const nameWithParams = parts[1];
//         const value = parts.slice(2).join(" ");

//         const match = nameWithParams.match(/^(FV|FNV|RV|RNV|TMR)/);
//         if (match) {
//           // Vérifier si c'est une macro avec (NumCase)
//           const paramMatch = nameWithParams.match(/\((\w+)\)/);
//           if (paramMatch) {
//             // On boucle sur toutes les cases (NBR_CASE)
//             const nbrCase = constants["NBR_CASE"] || 8;
//             for (let i = 0; i < nbrCase; i++) {
//               // Remplacer constantes et NumCase dans l'expression
//               let expr = value.replace(/\bNumCase\b/g, i);
//               Object.keys(constants).forEach((key) => {
//                 const regex = new RegExp(`\\b${key}\\b`, "g");
//                 expr = expr.replace(regex, constants[key]);
//               });

//               // Evaluer l'expression
//               let code = null;
//               try {
//                 code = eval(expr); // ⚠️ attention à l'évaluation dynamique
//               } catch (e) {
//                 code = null;
//               }

//               data.push({
//                 type: match[1],
//                 adresse: code,
//                 description: cleanName(nameWithParams, i),
//               });
//             }
//           } else {
//             // Macro sans paramètre, juste une constante
//             let code = null;
//             const numMatch = value.match(/\d+/);
//             if (numMatch) code = parseInt(numMatch[0]);

//             data.push({
//               type: match[1],
//               adresse: code,
//               description: cleanName(nameWithParams),
//             });
//           }
//         }
//       }
//     });

//     res.json(data);
//   });
// });
// Lire le fichier .h et transformer en JSON avec calcul des macros
app.post("/api/data", upload.single("file"), async (req, res) => {
  try {
    if (!req.file) {
      return res.status(400).json({ error: "No file uploaded" });
    }

    const tempFilePath = req.file.path;
    // const minioFileName = `uploads/${Date.now()}-${req.file.originalname}`;

    // Upload to MinIO
    // await uploadToMinio(tempFilePath, minioFileName);

    // Read file content
    const content = fs.readFileSync(tempFilePath, "utf8");

    // Delete temp file
    fs.unlinkSync(tempFilePath);

    const lines = content.split("\n");
    const constants = {};
    const data = [];

    // Lire toutes les constantes
    lines.forEach((line) => {
      line = line.trim();
      const constMatch = line.match(/^#define\s+(\w+)\s+(\d+)/);
      if (constMatch) {
        const name = constMatch[1];
        const value = parseInt(constMatch[2]);
        constants[name] = value;
      }
    });

    // Lire les macros avec paramètres
    lines.forEach((line) => {
      line = line.trim();
      if (line.startsWith("#define")) {
        const parts = line.split(/\s+/);
        const nameWithParams = parts[1];
        const value = parts.slice(2).join(" ");

        const match = nameWithParams.match(/^(FV|FNV|RV|RNV|TMR)/);
        if (match) {
          const paramMatch = nameWithParams.match(/\((\w+)\)/);
          if (paramMatch) {
            const nbrCase = constants["NBR_CASE"] || 8;
            for (let i = 0; i < nbrCase; i++) {
              let expr = value.replace(/\bNumCase\b/g, i);
              Object.keys(constants).forEach((key) => {
                const regex = new RegExp(`\\b${key}\\b`, "g");
                expr = expr.replace(regex, constants[key]);
              });

              let code = null;
              try {
                code = eval(expr);
              } catch (e) {
                code = null;
              }

              data.push({
                type: match[1],
                adresse: code,
                description: cleanName(nameWithParams, i),
              });
            }
          } else {
            let code = null;
            const numMatch = value.match(/\d+/);
            if (numMatch) code = parseInt(numMatch[0]);

            data.push({
              type: match[1],
              adresse: code,
              description: cleanName(nameWithParams),
            });
          }
        }
      }
    });

    res.json({ data });
  } catch (error) {
    console.error("✗ Error processing file:", error);
    res.status(500).json({ error: "Error processing file: " + error.message });
  }
});
// Generate Excel from .h file
app.post("/api/generate-excel", upload.single("file"), async (req, res) => {
  try {
    if (!req.file) {
      return res.status(400).json({ error: "No file uploaded" });
    }
    const tempFilePath = req.file.path;
    const { fileName, date } = req.body;

    // Read and parse .h file
    // const content = fs.readFileSync(filePath, "utf8");
    // Read and parse .h file
    const content = fs.readFileSync(tempFilePath, "utf8");

    // Delete temp .h file immediately after reading
    fs.unlinkSync(tempFilePath);
    const lines = content.split("\n");
    const constants = {};
    const parsedData = [];

    // Read all constants
    lines.forEach((line) => {
      line = line.trim();
      const constMatch = line.match(/^#define\s+(\w+)\s+(\d+)/);
      if (constMatch) {
        constants[constMatch[1]] = parseInt(constMatch[2]);
      }
    });

    // Read macros with parameters
    lines.forEach((line) => {
      line = line.trim();
      if (line.startsWith("#define")) {
        const parts = line.split(/\s+/);
        const nameWithParams = parts[1];
        const value = parts.slice(2).join(" ");

        const match = nameWithParams.match(/^(FV|FNV|RV|RNV|TMR)/);
        if (match) {
          const paramMatch = nameWithParams.match(/\((\w+)\)/);
          if (paramMatch) {
            const nbrCase = constants["NBR_CASE"] || 8;
            for (let i = 0; i < nbrCase; i++) {
              let expr = value.replace(/\bNumCase\b/g, i);
              Object.keys(constants).forEach((key) => {
                const regex = new RegExp(`\\b${key}\\b`, "g");
                expr = expr.replace(regex, constants[key]);
              });

              let code = null;
              try {
                code = eval(expr);
              } catch (e) {
                code = null;
              }

              parsedData.push({
                type: match[1],
                adresse: code,
                description: cleanName(nameWithParams, i),
              });
            }
          } else {
            let code = null;
            const numMatch = value.match(/\d+/);
            if (numMatch) code = parseInt(numMatch[0]);

            parsedData.push({
              type: match[1],
              adresse: code,
              description: cleanName(nameWithParams),
            });
          }
        }
      }
    });

    // Create Excel workbook
    const workbook = new ExcelJS.Workbook();

    // Helper function to create styled worksheet
    const createStyledSheet = (name, title, startAddress, rangeSize = 256) => {
      const worksheet = workbook.addWorksheet(name);

      // Title row
      worksheet.mergeCells("A1:O1");
      const titleCell = worksheet.getCell("A1");
      titleCell.value = title;
      titleCell.font = { bold: true, size: 22, color: { argb: "FFFFFFFF" } };
      titleCell.alignment = { horizontal: "center", vertical: "middle" };
      titleCell.fill = {
        type: "pattern",
        pattern: "solid",
        fgColor: { argb: "FF000000" },
      };

      // Create 4 tables
      const tables = [
        { col: 1, addr: startAddress },
        { col: 5, addr: startAddress + 256 },
        { col: 9, addr: startAddress + 512 },
        { col: 13, addr: startAddress + 768 },
      ];

      tables.forEach(({ col, addr }) => {
        // Headers
        worksheet.getCell(3, col).value = "Adresse";
        worksheet.getCell(3, col + 1).value = "Description";
        worksheet.getCell(3, col + 2).value = "Type";

        // Style headers
        for (let i = 0; i < 3; i++) {
          const cell = worksheet.getCell(3, col + i);
          cell.font = { bold: true };
          cell.alignment = { horizontal: "center" };
          cell.fill = {
            type: "pattern",
            pattern: "solid",
            fgColor: { argb: "FFD9D9D9" },
          };
          cell.border = {
            top: { style: "thin" },
            bottom: { style: "thin" },
            left: { style: "thin" },
            right: { style: "thin" },
          };
        }

        // Data rows
        for (let i = 0; i < rangeSize; i++) {
          const row = 4 + i;
          const address = addr + i;

          // Find matching data
          const matchingData = parsedData.find(
            (d) => d.adresse === address && d.type === name.split(" ")[0],
          );

          worksheet.getCell(row, col).value = address;
          worksheet.getCell(row, col + 1).value = matchingData
            ? matchingData.description
            : "";
          worksheet.getCell(row, col + 2).value = matchingData
            ? matchingData.type
            : "";

          // Style cells
          for (let c = 0; c < 3; c++) {
            const cell = worksheet.getCell(row, col + c);
            cell.border = {
              top: { style: "thin" },
              bottom: { style: "thin" },
              left: { style: "thin" },
              right: { style: "thin" },
            };
          }
        }
      });

      // Set column widths
      for (let i = 1; i <= 15; i++) {
        worksheet.getColumn(i).width = 18;
      }

      return worksheet;
    };

    // Info sheet
    const infoSheet = workbook.addWorksheet("Info");
    infoSheet.getCell("A1").value = "NAME";
    infoSheet.getCell("A1").font = {
      bold: true,
      size: 22,
      color: { argb: "FFFFFFFF" },
    };
    infoSheet.getCell("A1").alignment = {
      horizontal: "center",
      vertical: "center",
    };
    infoSheet.getCell("A1").fill = {
      type: "pattern",
      pattern: "solid",
      fgColor: { argb: "FF1F4E78" },
    };

    infoSheet.getCell("A2").value = fileName || "Unnamed";
    infoSheet.getCell("A2").font = { size: 16, bold: true };
    infoSheet.getCell("A2").alignment = { horizontal: "center" };

    infoSheet.getCell("A4").value = "DATE";
    infoSheet.getCell("A4").font = {
      bold: true,
      size: 20,
      color: { argb: "FFFFFFFF" },
    };
    infoSheet.getCell("A4").alignment = { horizontal: "center" };
    infoSheet.getCell("A4").fill = {
      type: "pattern",
      pattern: "solid",
      fgColor: { argb: "FF548235" },
    };

    infoSheet.getCell("A5").value =
      date || new Date().toISOString().split("T")[0];
    infoSheet.getCell("A5").font = { size: 14 };
    infoSheet.getCell("A5").alignment = { horizontal: "center" };

    infoSheet.getColumn(1).width = 30;

    // Create all data sheets
    createStyledSheet("RV", "Register Volatile", 0);
    createStyledSheet("RV 1024", "Register Volatile 1024", 1024);
    createStyledSheet("RV 2048", "Register Volatile 2048", 2048);
    createStyledSheet("RNV 20000", "Register Non Volatile 20000", 20000);
    createStyledSheet("RNV 21024", "Register Non Volatile 21024", 21024);
    createStyledSheet("RNV 22048", "Register Non Volatile 22048", 22048);
    createStyledSheet("RNV 23072", "Register Non Volatile 23072", 23072);
    createStyledSheet("FV", "Flag Volatile", 0);
    createStyledSheet("FV 1024", "Flag Volatile 1024", 1024);
    createStyledSheet("FV 2048", "Flag Volatile 2048", 2048);
    createStyledSheet("FV 3249", "Flag Volatile 3249", 3072);
    createStyledSheet("FNV 20000", "Flag Non Volatile 20000", 20000);
    createStyledSheet("FNV 21024", "Flag Non Volatile 21024", 21024);
    createStyledSheet("FNV 22048", "Flag Non Volatile 22048", 22048);
    createStyledSheet("Timer", "Timer", 0);
    createStyledSheet("Timer 1024", "Timer 1024", 1024);

    // Save Excel file temporarily
    const tempExcelPath = path.join("temp", `temp-${Date.now()}.xlsx`);
    await workbook.xlsx.writeFile(tempExcelPath);

    // Get file stats BEFORE deleting
    const fileStat = fs.statSync(tempExcelPath);

    // Upload ONLY Excel to MinIO
    const excelFileName = `excel/${fileName || "excel-file"}_${Date.now()}.xlsx`;
    await uploadToMinio(tempExcelPath, excelFileName);

    // Generate presigned URL for download (valid for 24 hours)
    const downloadUrl = await minioClient.presignedGetObject(
      BUCKET_NAME,
      excelFileName,
      24 * 60 * 60,
    );
    // ✅ SAVE IN DATABASE WITH PRISMA
    const savedFile = await prisma.file.create({
      data: {
        filename: path.basename(excelFileName),
        originalName: `${fileName || "excel-file"}.xlsx`,
        mimeType:
          "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet",
        size: fileStat.size,
        bucketName: BUCKET_NAME,
        objectKey: excelFileName,
        url: downloadUrl,
      },
    });
    // Delete temp Excel file
    fs.unlinkSync(tempExcelPath);

    res.json({
      success: true,
      // excelFileName: excelFileName,
      file: savedFile,
      downloadUrl: downloadUrl,
      message: "Excel generated and uploaded to MinIO successfully",
    });
  } catch (error) {
    console.error("✗ Error generating Excel:", error);
    res
      .status(500)
      .json({ error: "Error generating Excel file: " + error.message });
  }
});

// Endpoint to download file from MinIO
app.get("/api/download/:folder/:filename", async (req, res) => {
  try {
    const { folder, filename } = req.params;
    const fileName = `${folder}/${filename}`;

    if (!fileName) {
      return res.status(400).json({ error: "File name is required" });
    }

    console.log(`📥 Downloading file: ${fileName}`);

    // Get file from MinIO
    const fileBuffer = await getFileFromMinio(fileName);

    // Set headers
    res.setHeader(
      "Content-Type",
      "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet",
    );
    res.setHeader("Content-Disposition", `attachment; filename="${filename}"`);

    res.send(fileBuffer);
  } catch (error) {
    console.error("✗ Error downloading file:", error);
    res
      .status(500)
      .json({ error: "Error downloading file from MinIO: " + error.message });
  }
});

// Health check endpoint
app.get("/api/health", async (req, res) => {
  try {
    const bucketExists = await minioClient.bucketExists(BUCKET_NAME);
    res.json({
      status: "ok",
      minio: {
        connected: true,
        bucket: BUCKET_NAME,
        bucketExists: bucketExists,
      },
    });
  } catch (error) {
    res.status(500).json({
      status: "error",
      minio: {
        connected: false,
        error: error.message,
      },
    });
  }
});

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
  console.log(`\n✓ Backend server started on http://localhost:${PORT}`);
  console.log(`✓ MinIO endpoint: ${minioConfig.endPoint}:${minioConfig.port}`);
  console.log(`✓ MinIO bucket: ${BUCKET_NAME}\n`);
});
