#include "Sudoku.h"
#include <vector>

Sudoku::Sudoku() {
}

std::array<std::vector<int>, 3> Sudoku::getNum(int pos1, int pos2) {
    std::array<std::vector<int>, 3> num;
    for (int i = 0; i < N; i++) {
        num[0].push_back(i);
        num[1].push_back(i);
        num[2].push_back(i);
    }

    return num;
}

void Sudoku::generateGrid() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::vector<int> row;
        }
    }

}