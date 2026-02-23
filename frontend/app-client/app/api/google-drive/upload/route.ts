// import { NextRequest, NextResponse } from "next/server";
// import { google } from "googleapis";
// import { Readable } from "stream";

// export const runtime = "nodejs";

// export async function POST(req: NextRequest) {
//   try {
//     const { fileUrl, fileName } = await req.json();

//     if (!fileUrl) {
//       return NextResponse.json({ error: "No file URL provided" }, { status: 400 });
//     }

//     const response = await fetch(fileUrl);

//     if (!response.ok) {
//       return NextResponse.json({ error: "Failed to fetch file" }, { status: 400 });
//     }

//     const arrayBuffer = await response.arrayBuffer();
//     const buffer = Buffer.from(arrayBuffer);

//     //  Convert buffer to stream
//     const stream = Readable.from(buffer);

//     const auth = new google.auth.GoogleAuth({
//       credentials: {
//         client_email: process.env.GOOGLE_CLIENT_EMAIL,
//         private_key: process.env.GOOGLE_PRIVATE_KEY?.replace(/\\n/g, "\n"),
//       },
//       scopes: ["https://www.googleapis.com/auth/drive"],
//     });

//     const drive = google.drive({ version: "v3", auth });

//     const uploadResponse = await drive.files.create({
//       requestBody: {
//         name: fileName,
//       },
//       media: {
//         mimeType: "application/octet-stream",
//         body: stream,
//       },
//     });

//     return NextResponse.json({
//       success: true,
//       driveFileId: uploadResponse.data.id,
//     });
//   } catch (error: any) {
//     console.error("Drive Upload Error:", error?.message || error);
//     return NextResponse.json({ error: error?.message || "Upload failed" }, { status: 500 });
//   }
// }
import { NextRequest, NextResponse } from "next/server";
import { google } from "googleapis";
import { Readable } from "stream";

export const runtime = "nodejs";

export async function POST(req: NextRequest) {
  try {
    const { fileUrl, fileName } = await req.json();

    if (!fileUrl) {
      return NextResponse.json({ error: "No file URL provided" }, { status: 400 });
    }

    const response = await fetch(fileUrl);
    if (!response.ok) {
      return NextResponse.json({ error: "Failed to fetch file" }, { status: 400 });
    }

    const arrayBuffer = await response.arrayBuffer();
    const buffer = Buffer.from(arrayBuffer);
    const stream = Readable.from(buffer);

    const auth = new google.auth.GoogleAuth({
      credentials: {
        client_email: process.env.GOOGLE_CLIENT_EMAIL,
        private_key: process.env.GOOGLE_PRIVATE_KEY?.replace(/\\n/g, "\n"),
      },
      scopes: ["https://www.googleapis.com/auth/drive"],
    });

    const drive = google.drive({ version: "v3", auth });

    const uploadResponse = await drive.files.create({
      requestBody: {
        name: fileName,
        // 👇 Add the shared folder ID here
        parents: [process.env.GOOGLE_DRIVE_FOLDER_ID!],
      },
      media: {
        mimeType: "application/octet-stream",
        body: stream,
      },
      // Required to get the file ID back when using a shared drive
      fields: "id, name, webViewLink",
      // Uncomment these two lines if using a Shared Drive instead of a regular shared folder:
      // supportsAllDrives: true,
      // includeItemsFromAllDrives: true,
    });

    return NextResponse.json({
      success: true,
      driveFileId: uploadResponse.data.id,
      webViewLink: uploadResponse.data.webViewLink,
    });
  } catch (error: any) {
    console.error("Drive Upload Error:", error?.message || error);
    return NextResponse.json({ error: error?.message || "Upload failed" }, { status: 500 });
  }
}