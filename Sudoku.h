#pragma once
#include <array>
#include <random>
#include <time.h>

class Sudoku {
private:
    static const int N = 9;
    std::array<std::array<int, N>, N> grid;

    std::array<std::vector<int>, 3> Sudoku::getNum(int pos1, int pos2);

public:
    Sudoku();

    bool testLigne(std::array<std::array<int, N>, N> grid, int valeur, int y);
    bool testColonne(std::array<std::array<int, N>, N> grid, int valeur, int x);
    bool testCarre(std::array<std::array<int, N>, N> grid, int valeur, int x, int y);
    bool testValeur(std::array<std::array<int, N>, N> grid, int valeur, int x, int y);

    void resolve();

};