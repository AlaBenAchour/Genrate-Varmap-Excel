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

    // Largeur colonne
    wsInfo["!cols"] = [{ wch: 30 }];

    // NAME title
    wsInfo["A1"].s = {
      font: { bold: true, sz: 22, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center", vertical: "center" },
      fill: { fgColor: { rgb: "1F4E78" } },
    };

    wsInfo["A2"].s = {
      font: { sz: 16, bold: true },
      alignment: { horizontal: "center" },
    };

    // DATE title
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
     SHEET 2 : RV
  ====================== */

    const wsRVData: any[][] = [];
    const ROW_START = 3;
    const ROW_COUNT = 256;
    // Function pour créer un tableau
       const createTable = (startCol: number, startAddress: number) => {
      // Titre
      wsRVData[0] ??= [];
      wsRVData[0][startCol] = "Register Volatile";

      // Header
      wsRVData[2] ??= [];
      wsRVData[2][startCol] = "Adresse";
      wsRVData[2][startCol + 1] = "Description";
      wsRVData[2][startCol + 2] = "Type";

      // Contenu
      for (let i = 0; i < ROW_COUNT; i++) {
        const row = ROW_START + i;
        wsRVData[row] ??= [];
        wsRVData[row][startCol] = startAddress + i;
        wsRVData[row][startCol + 1] = "";
        wsRVData[row][startCol + 2] = "";
      }
    };
    // Répéter le tableau 4 fois horizontalement
    createTable(0, 0);
    createTable(4, 256);
    createTable(8, 512);
    createTable(12, 768);

    const wsRV = XLSX.utils.aoa_to_sheet(wsRVData);

    // Styles titre + header + cellules
    const styleTitle = {
      font: { bold: true, sz: 18, color: { rgb: "FFFFFF" } },
      alignment: { horizontal: "center" },
      fill: { fgColor: { rgb: "7030A0" } },
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
  //  const wsRV = XLSX.utils.aoa_to_sheet(wsRVData);

    // Fusion titre + styles
    [0, 4, 8, 12].forEach((col) => {
      wsRV["!merges"] ??= [];
      wsRV["!merges"].push({
        s: { r: 0, c: col },
        e: { r: 0, c: col + 2 },
      });

      wsRV[XLSX.utils.encode_cell({ r: 0, c: col })].s = styleTitle;

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
    // // Appliquer styles aux 4 tableaux
    // [0, 4, 8, 12].forEach((col) => {
    //   wsRV[XLSX.utils.encode_cell({ r: 0, c: col })].s = styleTitle;

    //   ["Adresse", "Description", "Type"].forEach((_, i) => {
    //     wsRV[XLSX.utils.encode_cell({ r: 2, c: col + i })].s = styleHeader;
    //   });

    //   for (let r = 3; r <= 7; r++) {
    //     for (let c = col; c <= col + 2; c++) {
    //       wsRV[XLSX.utils.encode_cell({ r, c })].s = styleCell;
    //     }
    //   }
    // });

    // // Largeur colonnes RV
    // wsRV["!cols"] = Array(15).fill({ wch: 20 });

    /* ======================
     WORKBOOK
  ====================== */

    const wb = XLSX.utils.book_new();
    XLSX.utils.book_append_sheet(wb, wsInfo, "Info");
    XLSX.utils.book_append_sheet(wb, wsRV, "RV");

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

          {/* <div className="mt-7 flex flex-col gap-2"> */}
          {/* <button className="inline-flex h-10 w-full items-center justify-center gap-2 rounded border border-slate-300 bg-white p-2 text-sm font-medium text-black outline-none focus:ring-2 focus:ring-[#333] focus:ring-offset-1 disabled:cursor-not-allowed disabled:opacity-60">
              <Image
                width={100}
                height={100}
                src="https://www.svgrepo.com/show/512317/github-142.svg"
                alt="GitHub"
                className="h-[18px] w-[18px] "
              />
              Continue with GitHub
            </button> */}

          {/* <button className="inline-flex h-10 w-full items-center justify-center gap-2 rounded border border-slate-300 bg-white p-2 text-sm font-medium text-black outline-none focus:ring-2 focus:ring-[#333] focus:ring-offset-1 disabled:cursor-not-allowed disabled:opacity-60">
              <Image
                width={100}
                height={100}
                src="https://www.svgrepo.com/show/475656/google-color.svg"
                alt="Google"
                className="h-[18px] w-[18px]"
              />
              Continue with Google
            </button> */}

          {/* <button className="inline-flex h-10 w-full items-center justify-center gap-2 rounded border border-slate-300 bg-white p-2 text-sm font-medium text-black outline-none focus:ring-2 focus:ring-[#333] focus:ring-offset-1 disabled:cursor-not-allowed disabled:opacity-60">
              <Image
                width={100}
                height={100}
                src="https://www.svgrepo.com/show/448234/linkedin.svg"
                alt="Google"
                className="h-[18px] w-[18px] "
              />
              Continue with LinkedIn
            </button> */}
          {/* </div> */}

          {/* <div className="flex w-full items-center gap-2 py-6 text-sm text-slate-600">
            <div className="h-px w-full bg-slate-200"></div>
            OR
            <div className="h-px w-full bg-slate-200"></div>
          </div> */}

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
            {/* <p className="mb-3 mt-2 text-sm text-gray-500">
              <a
                href="/forgot-password"
                className="text-blue-800 hover:text-blue-600"
              >
                Reset your password?
              </a>
            </p> */}
            <button
              type="submit"
              className="inline-flex mt-4 w-full items-center justify-center rounded-lg bg-black p-2 py-3 text-sm font-medium text-white outline-none focus:ring-2 focus:ring-black focus:ring-offset-1 disabled:bg-gray-400"
            >
              Generate
            </button>
          </form>

          {/* <div className="mt-6 text-center text-sm text-slate-600">
            Don&apos;t have an account?
            <a href="/signup" className="font-medium text-[#4285f4]">
              Sign up
            </a>
          </div> */}
        </div>
      </div>
    </div>
  );
};

export default GenerateModul;
