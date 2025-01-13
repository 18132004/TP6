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

bool Sudoku::testLigne(std::array<std::array<int, N>, N> grid, int valeur, int y) {
    for (int i = 0; i < N; i++) {
        if (grid[i][y] == valeur) {
            return false;
        }
    }
    return true;
}

bool Sudoku::testColonne(std::array<std::array<int, N>, N> grid, int valeur, int x) {
    for (int i = 0; i < N; i++) {
        if (grid[i][x] == valeur) {
            return false;
        }
    }
    return true;
}

bool Sudoku::testCarre(std::array<std::array<int, N>, N> grid, int valeur, int x, int y) {
    int tailleCarre = sqrt(N);
    // Trouver les coordonnées de départ du carré
    int x0 = x/tailleCarre * tailleCarre;
    int y0 = x/tailleCarre * tailleCarre;

    for (int i = x0; i < x0 + 3; i++) {
        for (int j = y0; j < y0 + 3; j++) {
            if (grid[i][j] == valeur) {
                return false;
            }
        }
    }
    return true;
}