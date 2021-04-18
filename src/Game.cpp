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

bool Game::dfs(int x) {
    if(x >= this->blank.size()) return false;
    for(int i = 1;i < 10;i++) {
        this->sudoku[blank[x] / 9][blank[x] % 9] = i + '0';
        if(x != this->blank.size() - 1) {if(dfs(x + 1)) return true;}
        else { if (this->check()) return true; }
    }
    return false;
}

bool Game::solve() {
    for(int i = 0;i < 9;i++)
        for(int j = 0;j < 9;j++) {
            cin >> this->sudoku[i][j];
            if(this->sudoku[i][j] == '$') {this->blank.push_back(i * 9 + j); continue;}
            if(this->sudoku[i][j] >= '0' && this->sudoku[i][j] <= '9') continue;
            else {
                cout << "invalid game!" << endl
                     << "Unknown number at " << this->sudoku[i][j] << endl;
                return false;
            }
        }

    if(this->dfs(0))
        for(int i = 0;i < 9;i ++) {
            for(int j = 0;j < 9;j++)
                cout << sudoku[i][j] << ' ';
            cout << endl;
        }
    else cout << "no answer!" << endl;

    return true;
}
