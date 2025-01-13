#include "Sudoku.h"
#include <cmath>

Sudoku::Sudoku() {}

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

bool Sudoku::testValeur(std::array<std::array<int, N>, N> grid, int valeur, int x, int y) {
    return testLigne(grid, valeur, y) && testColonne(grid, valeur, x) && testCarre(grid, valeur, x, y);
}

void Sudoku::resolve() {

}