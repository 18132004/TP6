#pragma once
#include <array>

class Sudoku {
private:
    static const int N = 9;
    std::array<int, N> grid;

    void permuteCase(int pos1, int pos2);

public:
    Sudoku();

    void generateGrid();

};