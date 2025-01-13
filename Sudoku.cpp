#include "Sudoku.h"
#include <cmath>

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

bool Sudoku::testLigne(int valeur, int y) {
    for (int i = 0; i < N; i++) {
        if (grid[i][y] == valeur) {
            return false;
        }
    }
    return true;
}

bool Sudoku::testColonne(int valeur, int x) {
    for (int i = 0; i < N; i++) {
        if (grid[i][x] == valeur) {
            return false;
        }
    }
    return true;
}

bool Sudoku::testCarre(int valeur, int x, int y) {
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

bool Sudoku::testValeur(int valeur, int x, int y) {
    return testLigne(valeur, y) && testColonne(valeur, x) && testCarre(valeur, x, y);
}