#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <iostream>
#include <unordered_map>
#include <string>

// Semantic Analyzer (Symbol Table)
class SemanticAnalyzer {
private:
    std::unordered_map<std::string, std::string> symbolTable;

public:
    void insert(const std::string& name, const std::string& type) {
        if (symbolTable.find(name) != symbolTable.end()) {
            std::cerr << "Error: Variable '" << name << "' redeclared.\n";
        } else {
            symbolTable[name] = type;
        }
    }

    std::string lookup(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            return "undefined";
        }
    }

    void print() const {
        std::cout << "Symbol Table:\n";
        for (const auto& entry : symbolTable) {
            std::cout << entry.first << ": " << entry.second << "\n";
        }
    }
};

#endif // SEMANTIC_H
