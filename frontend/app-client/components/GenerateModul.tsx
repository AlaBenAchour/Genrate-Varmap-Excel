"use client";
import React, { useState } from "react";
//import * as XLSX from "xlsx";
import * as XLSX from "xlsx-js-style";

const GenerateModul = ({
  handleShowModal,
}: {
  handleShowModal: () => void;
}) => {
  const [fileName, setFileName] = useState("");
  const [date, setDate] = useState("");

const handleGenerate = (e: React.FormEvent) => {
  e.preventDefault();

  /* ======================
     SHEET 1 : INFO
  ====================== */

  const infoData = [["NAME"], [fileName], [], ["DATE"], [date]];
  const wsInfo = XLSX.utils.aoa_to_sheet(infoData);

  wsInfo["!cols"] = [{ wch: 30 }];

  wsInfo["A1"].s = {
    font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
    alignment: { horizontal: "center", vertical: "center" },
    fill: { fgColor: { rgb: "1F4E78" } },
  };

  wsInfo["A2"].s = {
    font: { sz: 16, bold: true },
    alignment: { horizontal: "center" },
  };

  wsInfo["A4"].s = {
    font: { bold: true, sz: 20, color: { rgb: "FFFFFF" } },
    alignment: { horizontal: "center" },
    fill: { fgColor: { rgb: "548235" } },
  };

  wsInfo["A5"].s = {
    font: { sz: 14 },
    alignment: { horizontal: "center" },
  };

  /* ======================
     RV (0-1023)
  ====================== */

  const ROW_START = 3;
  const ROW_COUNT = 256;

  const wsRVData: any[][] = [];

  const createTable = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTable(wsRVData, 0, 0);
  createTable(wsRVData, 4, 256);
  createTable(wsRVData, 8, 512);
  createTable(wsRVData, 12, 768);

  wsRVData[0] = [];
  wsRVData[0][0] = "Register Volatile";

  const wsRV = XLSX.utils.aoa_to_sheet(wsRVData);

  wsRV["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsRV[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Register Volatile",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  const styleHeader = {
    font: { bold: true },
    alignment: { horizontal: "center" },
    fill: { fgColor: { rgb: "D9D9D9" } },
    border: {
      top: { style: "thin" },
      bottom: { style: "thin" },
      left: { style: "thin" },
      right: { style: "thin" },
    },
  };

  const styleCell = {
    border: {
      top: { style: "thin" },
      bottom: { style: "thin" },
      left: { style: "thin" },
      right: { style: "thin" },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsRV[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT; r++) {
      for (let c = col; c < col + 3; c++) {
        wsRV[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsRV["!cols"] = Array(15).fill({ wch: 18 });

  /* ======================
     RV 1024-2047
  ====================== */

  const ROW_COUNT2 = 256;
  const wsRV1024Data: any[][] = [];

  const createTableRV1024 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT2; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableRV1024(wsRV1024Data, 0, 1024);
  createTableRV1024(wsRV1024Data, 4, 1280);
  createTableRV1024(wsRV1024Data, 8, 1536);
  createTableRV1024(wsRV1024Data, 12, 1792);

  wsRV1024Data[0] = [];
  wsRV1024Data[0][0] = "Register Volatile 1024";

  const wsRV1024 = XLSX.utils.aoa_to_sheet(wsRV1024Data);

  wsRV1024["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsRV1024[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Register Volatile 1024",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsRV1024[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT2; r++) {
      for (let c = col; c < col + 3; c++) {
        wsRV1024[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsRV1024["!cols"] = Array(15).fill({ wch: 18 });
  /* ======================
     RV 2048-2431
  ====================== */

  const ROW_COUNT3 = 256;
  const wsRV2048Data: any[][] = [];

  const createTableRV2048 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT3; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableRV2048(wsRV2048Data, 0, 2048);
  createTableRV2048(wsRV2048Data, 4, 2304);
  createTableRV2048(wsRV2048Data, 8, 2560);
  createTableRV2048(wsRV2048Data, 12, 2816);

  wsRV2048Data[0] = [];
  wsRV2048Data[0][0] = "Register Volatile 2048";

  const wsRV2048 = XLSX.utils.aoa_to_sheet(wsRV2048Data);

  wsRV2048["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsRV2048[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Register Volatile 2048",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsRV2048[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT3; r++) {
      for (let c = col; c < col + 3; c++) {
        wsRV2048[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsRV2048["!cols"] = Array(15).fill({ wch: 18 });
     /* ======================
     RNV 20000-21023
  ====================== */

  const ROW_COUNT6 = 256;
  const wsRNV20000Data: any[][] = [];

  const createTableRNV20000 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT6; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableRNV20000(wsRNV20000Data, 0, 20000);
  createTableRNV20000(wsRNV20000Data, 4, 20256);
  createTableRNV20000(wsRNV20000Data, 8, 20512);
  createTableRNV20000(wsRNV20000Data, 12, 20768);

  wsRNV20000Data[0] = [];
  wsRNV20000Data[0][0] = "Register Non Volatile 20000";

  const wsRNV20000 = XLSX.utils.aoa_to_sheet(wsRNV20000Data);

  wsRNV20000["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsRNV20000[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Register Non Volatile 20000",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsRNV20000[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT6; r++) {
      for (let c = col; c < col + 3; c++) {
        wsRNV20000[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsRNV20000["!cols"] = Array(15).fill({ wch: 18 });
   /* ======================
     RNV 21024-22047
  ====================== */

  const ROW_COUNT4 = 256;
  const wsRNVData: any[][] = [];

  const createTableRNV = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT4; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableRNV(wsRNVData, 0, 21024);
  createTableRNV(wsRNVData, 4, 21280);
  createTableRNV(wsRNVData, 8, 21536);
  createTableRNV(wsRNVData, 12, 21792);


  wsRNVData[0] = [];
  wsRNVData[0][0] = "Register Non Volatile 21024";

  const wsRNV = XLSX.utils.aoa_to_sheet(wsRNVData);

  wsRNV["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsRNV[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Register Non Volatile 21024",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsRNV[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT4; r++) {
      for (let c = col; c < col + 3; c++) {
        wsRNV[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsRNV["!cols"] = Array(15).fill({ wch: 18 });
    /* ======================
     RNV 22048-23071
  ====================== */

  const ROW_COUNT5 = 256;
  const wsRNV22048Data: any[][] = [];

  const createTableRNV22048 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT5; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableRNV22048(wsRNV22048Data, 0, 22048);
  createTableRNV22048(wsRNV22048Data, 4, 22304);
  createTableRNV22048(wsRNV22048Data, 8, 22560);
  createTableRNV22048(wsRNV22048Data, 12, 22816);

  wsRNV22048Data[0] = [];
  wsRNV22048Data[0][0] = "Register Non Volatile 22048";

  const wsRNV22048 = XLSX.utils.aoa_to_sheet(wsRNV22048Data);

  wsRNV22048["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsRNV22048[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Register Non Volatile 22048",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsRNV22048[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT5; r++) {
      for (let c = col; c < col + 3; c++) {
        wsRNV22048[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsRNV22048["!cols"] = Array(15).fill({ wch: 18 });
     /* ======================
     RNV 23072-24095
  ====================== */

  const ROW_COUNT7 = 256;
  const wsRNV23072Data: any[][] = [];

  const createTableRNV23072 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT7; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableRNV23072(wsRNV23072Data, 0, 23072);
  createTableRNV23072(wsRNV23072Data, 4, 23328);
  createTableRNV23072(wsRNV23072Data, 8, 23584);
  createTableRNV23072(wsRNV23072Data, 12, 23840);

  wsRNV23072Data[0] = [];
  wsRNV23072Data[0][0] = "Register Non Volatile 23072";

  const wsRNV23072 = XLSX.utils.aoa_to_sheet(wsRNV23072Data);

  wsRNV23072["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsRNV23072[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Register Non Volatile 23072",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsRNV23072[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT7; r++) {
      for (let c = col; c < col + 3; c++) {
        wsRNV23072[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsRNV23072["!cols"] = Array(15).fill({ wch: 18 });
       /* ======================
     FV
  ====================== */

  const ROW_COUNT8 = 256;
  const wsFVData: any[][] = [];

  const createTableFV = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT8; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableFV(wsFVData, 0, 0);
  createTableFV(wsFVData, 4, 256);
  createTableFV(wsFVData, 8, 512);
  createTableFV(wsFVData, 12, 768);

  wsFVData[0] = [];
  wsFVData[0][0] = "Flag Volatile";

  const wsFV = XLSX.utils.aoa_to_sheet(wsFVData);

  wsFV["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsFV[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Flag Volatile",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsFV[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT8; r++) {
      for (let c = col; c < col + 3; c++) {
        wsFV[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsFV["!cols"] = Array(15).fill({ wch: 18 });
       /* ======================
     FV 1024
  ====================== */

  const ROW_COUNT9 = 256;
  const wsFV1024Data: any[][] = [];

  const createTableFV1024 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT9; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableFV1024(wsFV1024Data, 0, 1024);
  createTableFV1024(wsFV1024Data, 4, 1280);
  createTableFV1024(wsFV1024Data, 8, 1536);
  createTableFV1024(wsFV1024Data, 12, 1792);

  wsFV1024Data[0] = [];
  wsFV1024Data[0][0] = "Flag Volatile 1024";

  const wsFV1024 = XLSX.utils.aoa_to_sheet(wsFV1024Data);

  wsFV1024["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsFV1024[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Flag Volatile 1024",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsFV1024[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT9; r++) {
      for (let c = col; c < col + 3; c++) {
        wsFV1024[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsFV1024["!cols"] = Array(15).fill({ wch: 18 });
         /* ======================
     FV 2048
  ====================== */

  const ROW_COUNT10 = 256;
  const wsFV2048Data: any[][] = [];

  const createTableFV2048 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT10; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableFV2048(wsFV2048Data, 0, 2048);
  createTableFV2048(wsFV2048Data, 4, 2304);
  createTableFV2048(wsFV2048Data, 8, 2560);
  createTableFV2048(wsFV2048Data, 12, 2816);

  wsFV2048Data[0] = [];
  wsFV2048Data[0][0] = "Flag Volatile 2048";

  const wsFV2048 = XLSX.utils.aoa_to_sheet(wsFV2048Data);

  wsFV2048["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsFV2048[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Flag Volatile 2048",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsFV2048[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT10; r++) {
      for (let c = col; c < col + 3; c++) {
        wsFV2048[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsFV2048["!cols"] = Array(15).fill({ wch: 18 });
         /* ======================
     FV 3072
  ====================== */

  const ROW_COUNT11 = 256;
  const wsFV3249Data: any[][] = [];
  const createTableFV3249 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT11; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableFV3249(wsFV3249Data, 0, 3072);
  createTableFV3249(wsFV3249Data, 4, 3328);
  createTableFV3249(wsFV3249Data, 8, 3584);
  createTableFV3249(wsFV3249Data, 12, 3840);

  wsFV3249Data[0] = [];
  wsFV3249Data[0][0] = "Flag Volatile 3249";

  const wsFV3249 = XLSX.utils.aoa_to_sheet(wsFV3249Data);

  wsFV3249["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsFV3249[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Flag Volatile 3249",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsFV3249[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT11; r++) {
      for (let c = col; c < col + 3; c++) {
        wsFV3249[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsFV3249["!cols"] = Array(15).fill({ wch: 18 });
           /* ======================
     FNV 20000
  ====================== */

  const ROW_COUNT12 = 256;
  const wsFNV20000Data: any[][] = [];
  const createTableFNV20000 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT12; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableFNV20000(wsFNV20000Data, 0, 20000);
  createTableFNV20000(wsFNV20000Data, 4, 20256);
  createTableFNV20000(wsFNV20000Data, 8, 20512);
  createTableFNV20000(wsFNV20000Data, 12, 20768);

  wsFNV20000Data[0] = [];
  wsFNV20000Data[0][0] = "Flag Volatile 20000";

  const wsFNV20000 = XLSX.utils.aoa_to_sheet(wsFNV20000Data);

  wsFNV20000["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsFNV20000[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Flag Volatile 20000",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsFNV20000[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT12; r++) {
      for (let c = col; c < col + 3; c++) {
        wsFNV20000[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsFNV20000["!cols"] = Array(15).fill({ wch: 18 });
           /* ======================
     FNV 21024
  ====================== */

  const ROW_COUNT13 = 256;
  const wsFNV21024Data: any[][] = [];
  const createTableFNV21024 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT13; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableFNV21024(wsFNV21024Data, 0, 21024);
  createTableFNV21024(wsFNV21024Data, 4, 21280);
  createTableFNV21024(wsFNV21024Data, 8, 21536);
  createTableFNV21024(wsFNV21024Data, 12, 21792);

  wsFNV21024Data[0] = [];
  wsFNV21024Data[0][0] = "Flag Volatile 21024";

  const wsFNV21024 = XLSX.utils.aoa_to_sheet(wsFNV21024Data);

  wsFNV21024["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsFNV21024[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Flag Volatile 21024",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsFNV21024[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT13; r++) {
      for (let c = col; c < col + 3; c++) {
        wsFNV21024[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsFNV21024["!cols"] = Array(15).fill({ wch: 18 });
             /* ======================
     FNV 22048
  ====================== */

  const ROW_COUNT14 = 256;
  const wsFNV22048Data: any[][] = [];
  const createTableFNV22048 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT14; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableFNV22048(wsFNV22048Data, 0, 22048);
  createTableFNV22048(wsFNV22048Data, 4, 22304);
  createTableFNV22048(wsFNV22048Data, 8, 22560);
  createTableFNV22048(wsFNV22048Data, 12, 22816);

  wsFNV22048Data[0] = [];
  wsFNV22048Data[0][0] = "Flag Volatile 22048";

  const wsFNV22048 = XLSX.utils.aoa_to_sheet(wsFNV22048Data);

  wsFNV22048["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsFNV22048[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Flag Volatile 22048",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsFNV22048[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT14; r++) {
      for (let c = col; c < col + 3; c++) {
        wsFNV22048[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsFNV22048["!cols"] = Array(15).fill({ wch: 18 });
               /* ======================
     Timer
  ====================== */

  const ROW_COUNT15 = 256;
  const wsTimerData: any[][] = [];
  const createTableTimer = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT15; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableTimer(wsTimerData, 0, 0);
  createTableTimer(wsTimerData, 4, 256);
  createTableTimer(wsTimerData, 8, 512);
  createTableTimer(wsTimerData, 12, 768);

  wsTimerData[0] = [];
  wsTimerData[0][0] = "Timer";

  const wsTimer = XLSX.utils.aoa_to_sheet(wsTimerData);

  wsTimer["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsTimer[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Timer",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsTimer[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT15; r++) {
      for (let c = col; c < col + 3; c++) {
        wsTimer[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsTimer["!cols"] = Array(15).fill({ wch: 18 });
                 /* ======================
     Timer 1024
  ====================== */

  const ROW_COUNT16 = 256;
  const wsTimer1024Data: any[][] = [];
  const createTableTimer1024 = (data: any[][], startCol: number, startAddress: number) => {
    data[2] ??= [];
    data[2][startCol] = "Adresse";
    data[2][startCol + 1] = "Description";
    data[2][startCol + 2] = "Type";

    for (let i = 0; i < ROW_COUNT16; i++) {
      const row = ROW_START + i;
      data[row] ??= [];
      data[row][startCol] = startAddress + i;
      data[row][startCol + 1] = "";
      data[row][startCol + 2] = "";
    }
  };

  createTableTimer1024(wsTimer1024Data, 0, 1024);
  createTableTimer1024(wsTimer1024Data, 4, 1280);
  createTableTimer1024(wsTimer1024Data, 8, 1536);
  createTableTimer1024(wsTimer1024Data, 12, 1792);

  wsTimer1024Data[0] = [];
  wsTimer1024Data[0][0] = "Timer 1024";

  const wsTimer1024 = XLSX.utils.aoa_to_sheet(wsTimer1024Data);

  wsTimer1024["!merges"] = [{ s: { r: 0, c: 0 }, e: { r: 0, c: 14 } }];
  wsTimer1024[XLSX.utils.encode_cell({ r: 0, c: 0 })] = {
    v: "Timer 1024",
    s: {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "000000" } },
    },
  };

  [0, 4, 8, 12].forEach((col) => {
    for (let i = 0; i < 3; i++) {
      wsTimer1024[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    }

    for (let r = ROW_START; r < ROW_START + ROW_COUNT16; r++) {
      for (let c = col; c < col + 3; c++) {
        wsTimer1024[XLSX.utils.encode_cell({ r, c })].s = styleCell;
      }
    }
  });

  wsTimer1024["!cols"] = Array(15).fill({ wch: 18 });
  /* ======================
     WORKBOOK
  ====================== */

  const wb = XLSX.utils.book_new();
  XLSX.utils.book_append_sheet(wb, wsInfo, "Info");
  XLSX.utils.book_append_sheet(wb, wsRV, "RV");
  XLSX.utils.book_append_sheet(wb, wsRV1024, "RV 1024");
  XLSX.utils.book_append_sheet(wb, wsRV2048, "RV 2048");
  XLSX.utils.book_append_sheet(wb, wsRNV20000, "RNV 20000");
  XLSX.utils.book_append_sheet(wb, wsRNV, "RNV 21024");
  XLSX.utils.book_append_sheet(wb, wsRNV22048, "RNV 22048");
  XLSX.utils.book_append_sheet(wb, wsRNV23072, "RNV 23072");
  XLSX.utils.book_append_sheet(wb, wsFV, "FV");
  XLSX.utils.book_append_sheet(wb, wsFV1024, "FV 1024");
  XLSX.utils.book_append_sheet(wb, wsFV2048, "FV 2048");
  XLSX.utils.book_append_sheet(wb, wsFV3249, "FV 3249");
  XLSX.utils.book_append_sheet(wb, wsFNV20000, "FNV 20000");
  XLSX.utils.book_append_sheet(wb, wsFNV21024, "FNV 21024");
  XLSX.utils.book_append_sheet(wb, wsFNV22048, "FNV 22048");
  XLSX.utils.book_append_sheet(wb, wsTimer, "Timer");
  XLSX.utils.book_append_sheet(wb, wsTimer1024, "Timer 1024");

  XLSX.writeFile(wb, `${fileName || "excel-file"}.xlsx`);
  handleShowModal();
};


  return (
    <div
      className="fixed inset-0 z-50 flex items-center justify-center bg-black/50 backdrop-blur-md overflow-x-hidden"
      onClick={handleShowModal}
    >
      <div
        onClick={(e) => e.stopPropagation()}
        className="relative bg-white rounded-lg shadow w-full max-w-md px-6 sm:px-10"
      >
        <button
          type="button"
          className="absolute top-3 right-2.5 text-gray-400 bg-transparent hover:bg-gray-200 hover:text-gray-900 rounded-lg text-sm p-1.5 ml-auto inline-flex items-center popup-close"
          onClick={handleShowModal}
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
          <h3 className="text-2xl mb-0.5 font-medium"></h3>
          <p className="mb-4 text-sm font-normal text-gray-800"></p>

          <div className="text-center">
            <p className="mb-3 text-2xl font-semibold leading-5 text-slate-900">
              Generate Excel
            </p>
            <p className="mt-2 text-sm leading-4 text-slate-600">
              Enter file name and date
            </p>
          </div>

          <form className="w-full gap-2 py-6" onSubmit={handleGenerate}>
            <label htmlFor="email" className="sr-only">
              Name Excel
            </label>
            <input
              value={fileName}
              onChange={(e) => setFileName(e.target.value)}
              name="text"
              type="text"
              autoComplete="text"
              required
              className="block w-full rounded-lg border border-gray-300 px-3 py-2 shadow-sm outline-none placeholder:text-gray-400 focus:ring-2 focus:ring-black focus:ring-offset-1"
              placeholder="Name Excel"
            />
            <label className="sr-only">Date</label>
            <input
              value={date}
              onChange={(e) => setDate(e.target.value)}
              name="date"
              type="date"
              autoComplete="current-date"
              required
              className="mt-2 block w-full rounded-lg border border-gray-300 px-3 py-2 shadow-sm outline-none placeholder:text-gray-400 focus:ring-2 focus:ring-black focus:ring-offset-1"
              placeholder="Date"
            />
            <button
              type="submit"
              className="inline-flex mt-4 w-full items-center justify-center rounded-lg bg-black p-2 py-3 text-sm font-medium text-white outline-none focus:ring-2 focus:ring-black focus:ring-offset-1 disabled:bg-gray-400"
            >
              Generate
            </button>
          </form>
        </div>
      </div>
    </div>
  );
};

export default GenerateModul;
