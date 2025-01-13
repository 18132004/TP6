#include "Sudoku.h"

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

std::vector<int> Sudoku::getListValibNb(int posX, int posY) {
    std::vector<int> listValidNb;

    // Tableau pour suivre les numéros déjà utilisés (1 à N)
    std::vector<bool> used(N + 1, false);

    // Vérifier les nombres présents dans la ligne
    for (int x = 0; x < N; ++x) {
        if (grid[x][posY] != 0) {
            used[grid[x][posY]] = true;
        }
    }

    // Vérifier les nombres présents dans la colonne
    for (int y = 0; y < N; ++y) {
        if (grid[posX][y] != 0) {
            used[grid[posX][y]] = true;
        }
    }

    // Vérifier les nombres présents dans la mini-grille
    int squareSize = static_cast<int>(std::sqrt(N)); // Taille d'un sous-carré
    int startX = (posX / squareSize) * squareSize;
    int startY = (posY / squareSize) * squareSize;

    for (int x = startX; x < startX + squareSize; ++x) {
        for (int y = startY; y < startY + squareSize; ++y) {
            if (grid[x][y] != 0) {
                used[grid[x][y]] = true;
            }
        }
    }

    // Ajouter les numéros valides à la liste
    for (int num = 1; num <= N; ++num) {
        if (!used[num]) {
            listValidNb.push_back(num);
        }
    }

    return listValidNb;
}

void Sudoku::resolve() {
    int x = 0;
    int y = 0;
    while (y < N) {
        if (grid[x][y] == 0) {
            std::vector<int> listValidNb = getListValibNb(x, y);
            // Si la liste est vide, on retourne en arrière
            if (listValidNb.empty()) {
                if (x == 0) {
                    x = N - 1;
                    y--;
                }
                else {
                    x--;
                }
            }
            // Si oui, on place un nombre (aléatoire parmi la liste)
            else {
                grid[x][y] = listValidNb[rand() % listValidNb.size()];
                if (x == N - 1) {
                    x = 0;
                    y++;
                }
                else {
                    x++;
                }
                display();
            }
        }
        else {
            if (x == N - 1) {
                x = 0;
                y++;
            }
            else {
                x++;
            }
        }
    }
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
