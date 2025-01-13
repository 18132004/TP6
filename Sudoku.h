#pragma once
#include <iostream>
#include <array>
#include <random>
#include <time.h>
#include <iostream>
class Sudoku {
private:
    static const int N = 9;
    std::array<std::array<int, N>, N> grid = { 0 };

public:
    Sudoku();

    bool testLigne(int valeur, int y);
    bool testColonne(int valeur, int x);
    bool testCarre(int valeur, int x, int y);
    bool testValeur(int valeur, int x, int y);

    std::vector<int> getListValibNb(int posX, int posY);
    void resolve();
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku);
    };

    void display();

};
