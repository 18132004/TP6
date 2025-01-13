#pragma once
#include <array>
#include <random>
#include <time.h>

class Sudoku {
private:
    static const int N = 9;
    std::array<std::array<int, N>, N> grid;

    std::vector<int> Sudoku::getNum(int pos1, int pos2);

public:
    Sudoku();

    void generateGrid();

};