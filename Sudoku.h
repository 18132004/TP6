#pragma once
#include <array>
#include <random>
#include <time.h>
#include <iostream>
class Sudoku {
private:
    static const int N = 9;
    std::array<std::array<int, N>, N> grid;



public:
    Sudoku();

    void generateGrid();

    bool testLigne(int valeur, int y);
    bool testColonne(int valeur, int x);
    bool testCarre(int valeur, int x, int y);
    bool testValeur(int valeur, int x, int y);

    void resolve();
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku);
    };

    