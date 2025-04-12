#include "semantic.h"
#include <iostream>
using namespace std;

// Define the global instance of SemanticAnalyzer
SemanticAnalyzer analyzer;

// Insert a new symbol (name and type) into the symbol table
void SemanticAnalyzer::insert(const string& name, const string& type) {
    for (const auto& sym : symbolTable) {
        if (sym.name == name) {
            cerr << "Semantic Error: Variable '" << name << "' redeclared.\n";
            return;
        }
    }
    symbolTable.push_back({name, type});
}

// Print the symbol table (name and type of all symbols)
void SemanticAnalyzer::print() const {
    cout << "\nSymbol Table:\n";
    cout << "Name\tType\n----------------\n";
    for (const auto& sym : symbolTable) {
        cout << sym.name << "\t" << sym.type << "\n";
    }
}
