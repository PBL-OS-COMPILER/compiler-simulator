#include "parser.h"
#include "semantic.h"

int main() {
    // Parse code from input file 'input.cpp'
    auto ast = parseCode("input.cpp");

    // Example: Checking for undeclared variable usage before printing the symbol table and AST
    std::vector<std::string> usedVariables = {"z"};  // 'z' is used but not declared
    analyzer.checkUndeclaredVariables(usedVariables);

    // Print Abstract Syntax Tree
    std::cout << "\n--- Abstract Syntax Tree ---\n";
    printAST(ast);

    // Print Symbol Table
    std::cout << "\n--- Semantic Analysis ---\n";
    analyzer.print();

    return 0;
}
