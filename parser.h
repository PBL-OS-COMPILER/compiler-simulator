#ifndef PARSER_H
#define PARSER_H

#include "ast.h"
#include <string>
#include <vector>

ASTNode* parseCode(const std::string& filename);
void printAST(ASTNode* node, int indent = 0);

#endif // PARSER_H
