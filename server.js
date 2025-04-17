const express = require("express");
const fs = require("fs");
const { exec } = require("child_process");
const app = express();
const PORT = 3000;

app.use(express.static("."));
app.use(express.json());

app.post("/tokenize", (req, res) => {
  const code = req.body.code;
  fs.writeFileSync("Code.txt", code);

  exec("lexer.exe", (error, stdout, stderr) => {
    if (error) {
      console.error("Error:", error.message);
      console.error("stderr:", stderr);
      return res.json({ tokens: "Error during tokenization." });
    }
    const tokens = fs.readFileSync("tokens.txt", "utf8");
    res.json({ tokens });
  });
  
});

app.listen(PORT, () => console.log(`Server running on http://localhost:${PORT}`));
