const express = require("express");
const cors = require("cors");
const fs = require("fs");
const path = require("path");

const app = express();
app.use(cors());
// Fonction pour mettre la première lettre de chaque mot en majuscule
function capitalizeWords(str) {
  return str.replace(/\b\w/g, char => char.toUpperCase());
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

// Lire le fichier .h et transformer en JSON avec calcul des macros
app.get("/api/data", (req, res) => {
  const filePath = path.join(__dirname, "files", "ventilation.h");

  fs.readFile(filePath, "utf8", (err, content) => {
    if (err) {
      return res.status(500).json({ error: "Erreur lecture fichier" });
    }

    const lines = content.split("\n");

    const constants = {};
    const data = [];

    // 1️⃣ Lire toutes les constantes
    lines.forEach(line => {
      line = line.trim();
      const constMatch = line.match(/^#define\s+(\w+)\s+(\d+)/);
      if (constMatch) {
        const name = constMatch[1];
        const value = parseInt(constMatch[2]);
        constants[name] = value;
      }
    });

    // 2️⃣ Lire les macros avec paramètres
    lines.forEach(line => {
      line = line.trim();
      if (line.startsWith("#define")) {
        const parts = line.split(/\s+/);
        const nameWithParams = parts[1];
        const value = parts.slice(2).join(" ");

        const match = nameWithParams.match(/^(FV|FNV|RV|RNV|TMR)/);
        if (match) {
          // Vérifier si c'est une macro avec (NumCase)
          const paramMatch = nameWithParams.match(/\((\w+)\)/);
          if (paramMatch) {
            // On boucle sur toutes les cases (NBR_CASE)
            const nbrCase = constants["NBR_CASE"] || 8;
            for (let i = 0; i < nbrCase; i++) {
              // Remplacer constantes et NumCase dans l'expression
              let expr = value.replace(/\bNumCase\b/g, i);
              Object.keys(constants).forEach(key => {
                const regex = new RegExp(`\\b${key}\\b`, "g");
                expr = expr.replace(regex, constants[key]);
              });

              // Evaluer l'expression
              let code = null;
              try {
                code = eval(expr); // ⚠️ attention à l'évaluation dynamique
              } catch (e) {
                code = null;
              }

              data.push({
                type: match[1],
                code: code,
                name: cleanName(nameWithParams, i)
              });
            }
          } else {
            // Macro sans paramètre, juste une constante
            let code = null;
            const numMatch = value.match(/\d+/);
            if (numMatch) code = parseInt(numMatch[0]);

            data.push({
              type: match[1],
              code: code,
              name: cleanName(nameWithParams)
            });
          }
        }
      }
    });

    res.json(data);
  });
});

app.listen(5000, () => {
  console.log("Backend lancé sur http://localhost:5000");
});
