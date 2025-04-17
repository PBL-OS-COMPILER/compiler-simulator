#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class SemanticAnalyzer {
public:
    void insert(const std::string& name, const std::string& type);
    void print() const;
    void checkUndeclaredVariables(const std::vector<std::string>& usedVariables) const;

private:
    std::unordered_map<std::string, std::string> symbolTable;  // Unordered map for symbol table
};

extern SemanticAnalyzer analyzer;

#endif // SEMANTIC_H
