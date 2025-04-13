#include "semantic.h"
#include <iostream>

SemanticAnalyzer analyzer;

// Insert a new symbol (name and type) into the symbol table
void SemanticAnalyzer::insert(const std::string& name, const std::string& type) {
    if (symbolTable.find(name) != symbolTable.end()) {
        std::cerr << "Semantic Error: Variable '" << name << "' redeclared.\n";
    } else {
        symbolTable[name] = type;  // Insert in unordered_map
    }
}

// Print the symbol table (name and type of all symbols)
void SemanticAnalyzer::print() const {
    std::cout << "\nSymbol Table:\n";
    std::cout << "Name\tType\n----------------\n";
    for (const auto& sym : symbolTable) {
        std::cout << sym.first << "\t" << sym.second << "\n";
    }
}

// Check for undeclared variables (called after AST creation or during parsing)
void SemanticAnalyzer::checkUndeclaredVariables(const std::vector<std::string>& usedVariables) const {
    for (const auto& var : usedVariables) {
        if (symbolTable.find(var) == symbolTable.end()) {
            std::cerr << "Semantic Error: Variable '" << var << "' used but not declared.\n";
        }
    }
}
