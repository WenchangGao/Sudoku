#include "../include/Game.h"
#include <iostream>
#include <cstring>

using namespace std;

Game::Game() {

}

bool Game::check() {
    int current;
    bool tapped[10];
    // vertical
    for(int i = 0;i < 9;i++) {
        memset(tapped, 0, sizeof(tapped));
        for(int j = 0;j < 9;j++) {
            current = (int) (sudoku[i][j] - '0');
            if(!tapped[current]) tapped[current] = true;
            else return false;
        }
    }
    // horizontal
    for(int i = 0;i < 9;i++) {
        memset(tapped, 0, sizeof(tapped));
        for(int j = 0;j < 9;j++) {
            current = (int) (sudoku[j][i] - '0');
            if(!tapped[current]) tapped[current] = true;
            else return false;
        }
    }
    // grids
    for(int grid = 0;grid < 9;grid++) {
        int x = grid % 3,y = grid / 3;
        memset(tapped, 0, sizeof(tapped));
        for(int i = 0;i < 3;i++) {
            for(int j = 0;j < 3;j++) {
                current = (int) (sudoku[i + x * 3][j + y * 3] - '0');
                if(!tapped[current]) tapped[current] = true;
                else return false;
            }
        }
    }
    return true;
}

bool Game::solve() {
    for(int i = 0;i < 9;i++)
        for(int j = 0;j < 9;j++) {
            cin >> this->sudoku[i][j];
            if(this->sudoku[i][j] == '$') this->blank.push_back(i * 9 + j);
            if(this->sudoku[i][j] >= '0' && this->sudoku[i][j] <= '9') continue;
            else {
                cout << "invalid game!" << endl
                     << "Unknown number at " << this->sudoku[i][j] << endl;
                return false;
            }
        }
    return true;
}
