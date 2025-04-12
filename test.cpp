#include <iostream>
#include "semantic.h"  // Include the header for SemanticAnalyzer

using namespace std;

extern SemanticAnalyzer analyzer;  // Declare the global instance of SemanticAnalyzer

int main() {
    analyzer.insert("x", "int");
    int x = 5;
    cout << "x = " << x << endl;

    analyzer.insert("y", "int");
    int y = 10;
    cout << "y = " << y << endl;

    analyzer.insert("z", "int");
    int z = 15;
    cout << "z = " << z << endl;

    analyzer.print();

    return 0;
}
