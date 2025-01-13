#include "Sudoku.h"
#include <iostream>

void printTestResult(const std::string& testName, bool result) {
    std::cout << testName << ": " << (result ? "Passed" : "Failed") << std::endl;
}

int main() {
    Sudoku sudoku;
    sudoku.generateGrid();

    // Test cases for testLigne
    printTestResult("testLigne (should be true)", sudoku.testLigne(sudoku.grid, 1, 0));
    printTestResult("testLigne (should be false)", !sudoku.testLigne(sudoku.grid, 0, 0));

    // Test cases for testColonne
    printTestResult("testColonne (should be true)", sudoku.testColonne(sudoku.grid, 1, 0));
    printTestResult("testColonne (should be false)", !sudoku.testColonne(sudoku.grid, 0, 0));

    // Test cases for testCarre
    printTestResult("testCarre (should be true)", sudoku.testCarre(sudoku.grid, 1, 0, 0));
    printTestResult("testCarre (should be false)", !sudoku.testCarre(sudoku.grid, 0, 0, 0));

    // Test cases for testValeur
    printTestResult("testValeur (should be true)", sudoku.testValeur(sudoku.grid, 1, 0, 0));
    printTestResult("testValeur (should be false)", !sudoku.testValeur(sudoku.grid, 0, 0, 0));


    return 0;
}