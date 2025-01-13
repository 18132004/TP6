#include "Sudoku.h"
#include <cmath>

Sudoku::Sudoku() {}

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

void Sudoku::resolve() {

}

std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku) {
    for (int i = 0; i < Sudoku::N; i++) {
        for (int j = 0; j < Sudoku::N; j++) {
            os << sudoku.grid[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
};