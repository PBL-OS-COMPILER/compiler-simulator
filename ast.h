#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ASTNode definition
struct ASTNode
{
    std::string type;  // e.g., "Declaration", "Expression"
    std::string value; // e.g., variable name or operator
    std::vector<std::shared_ptr<ASTNode>> children;

    ASTNode(const std::string &t, const std::string &v) : type(t), value(v) {}
};

// AST printing function
void printAST(const std::shared_ptr<ASTNode> &node, int indent = 0)
{
    std::cout << std::string(indent, ' ') << node->type << ": " << node->value << "\n";
    for (const auto &child : node->children)
    {
        printAST(child, indent + 2);
    }
}

#endif // AST_H
