#include "parser.h"
#include "semantic.h"
#include <fstream>
#include <sstream>
#include <iostream>

ASTNode* parseCode(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    ASTNode* program = new ASTNode{"Program"};
    ASTNode* lastDecl = program;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type, name;
        if (iss >> type >> name) {
            ASTNode* declNode = new ASTNode{"Declaration"};
            declNode->children.push_back(new ASTNode{type});
            declNode->children.push_back(new ASTNode{name});
            lastDecl->children.push_back(declNode);

            // Insert symbol into the symbol table
            analyzer.insert(name, type); // Check for redeclaration here
        }
    }

    return program;
}

void printAST(ASTNode* node, int indent) {
    if (node == nullptr) return;

    for (int i = 0; i < indent; ++i) std::cout << "  ";
    std::cout << node->name << std::endl;

    for (auto& child : node->children) {
        printAST(child, indent + 1);
    }
}
