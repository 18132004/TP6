#include "Sudoku.h"

Sudoku::Sudoku() {}

void Sudoku::permuteCase(int pos1, int pos2) {
    int temp = grid[pos1];
    grid[pos1] = grid[pos2];
    grid[pos2] = temp;
}

void Sudoku::generateGrid() {
    for (int i = 0; i < N; i++) {
        grid[i] = i % N;
    }

}