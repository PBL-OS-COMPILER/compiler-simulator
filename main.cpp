#include "ast.h"
#include "semantic.h"
#include <fstream>
#include <sstream>

SemanticAnalyzer analyzer;

void analyzeAST(const std::shared_ptr<ASTNode> &node)
{
    if (node->type == "Declaration")
    {
        std::string varName = node->value;
        std::string varType = node->children[0]->value;
        analyzer.insert(varName, varType);
    }

    for (const auto &child : node->children)
    {
        analyzeAST(child);
    }

    if (node->type == "Expression" && node->value == "+")
    {
        std::string lhs = node->children[0]->value;
        std::string rhs = node->children[1]->value;
        std::string lhsType = analyzer.lookup(lhs);
        std::string rhsType = analyzer.lookup(rhs);
        if (lhsType != rhsType)
        {
            std::cerr << "Type mismatch: " << lhs << " (" << lhsType << ") + "
                      << rhs << " (" << rhsType << ")\n";
        }
    }
}

std::shared_ptr<ASTNode> parseLine(const std::string &line)
{
    std::istringstream iss(line);
    std::string type, name, eq, val;

    iss >> type >> name;
    if (iss >> eq >> val)
    {
        // Remove trailing semicolon
        if (!val.empty() && val.back() == ';')
            val.pop_back();

        auto decl = std::make_shared<ASTNode>("Declaration", name);
        decl->children.push_back(std::make_shared<ASTNode>("Type", type));

        // Check if value is an expression
        if (val.find('+') != std::string::npos)
        {
            auto expr = std::make_shared<ASTNode>("Expression", "+");
            std::istringstream exprStream(val);
            std::string var1, plus, var2;
            exprStream >> var1 >> plus >> var2;
            expr->children.push_back(std::make_shared<ASTNode>("Variable", var1));
            expr->children.push_back(std::make_shared<ASTNode>("Variable", var2));
            decl->children.push_back(expr);
        }
        else
        {
            decl->children.push_back(std::make_shared<ASTNode>("Value", val));
        }

        return decl;
    }

    return nullptr;
}

int main()
{
    std::ifstream infile("program.cpp");
    if (!infile)
    {
        std::cerr << "Error: Could not open input file.\n";
        return 1;
    }

    auto root = std::make_shared<ASTNode>("Program", "");
    std::string line;

    while (std::getline(infile, line))
    {
        auto node = parseLine(line);
        if (node)
        {
            root->children.push_back(node);
        }
    }

    std::cout << "\n--- Abstract Syntax Tree ---\n";
    printAST(root);

    std::cout << "\n--- Semantic Analysis ---\n";
    analyzeAST(root);
    analyzer.print();

    return 0;
}
