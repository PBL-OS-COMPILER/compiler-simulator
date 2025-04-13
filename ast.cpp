// ASTNode.h
#ifndef AST_NODE_H
#define AST_NODE_H

#include <string>
#include <vector>

struct ASTNode {
    std::string name;         // The type of node (e.g., "Program", "Declaration")
    std::vector<ASTNode*> children;  // Child nodes (e.g., "int", "x" in a declaration)

    ASTNode(const std::string& n) : name(n) {}
};

#endif // AST_NODE_H
