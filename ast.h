#ifndef AST_NODE_H
#define AST_NODE_H

#include <string>
#include <vector>

struct ASTNode {
    std::string name;  // Type of the node (e.g., "Program", "Declaration")
    std::vector<ASTNode*> children;  // Child nodes (e.g., type, name in a declaration)

    ASTNode(const std::string& n) : name(n) {}  // Constructor to initialize name
};

#endif // AST_NODE_H
