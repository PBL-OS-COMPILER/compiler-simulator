#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <string>
#include <vector>
#include <iostream>

struct Symbol {
    std::string name; // Symbol's name (variable or function)
    std::string type; // Symbol's type (int, float, etc.)
};

class SemanticAnalyzer {
public:
    void insert(const std::string& name, const std::string& type);
    void print() const;

private:
    std::vector<Symbol> symbolTable;
};

// Declare the global instance of SemanticAnalyzer (defined in semantic.cpp)
extern SemanticAnalyzer analyzer;

#endif // SEMANTIC_H
