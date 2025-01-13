#pragma once
#include <vector>

class Sudoku {
private:
    int N;
    std::vector<int> grid;

public:
    Sudoku(int _N);

    void generateGrid();

};