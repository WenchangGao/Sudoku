#include "../include/Game.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

extern int count; // number of solved games, 1 <= count <= 10000000 -c
extern string path; // path -s
extern int number; // number of games to be generated, 1 <= number <= 10000 -n
extern int level; // difficulty level, 1 2 3 -m
extern int blanks; // number of blanks in the game to be filled, 20 <= blanks <= 55 -r
extern bool unique; // whether the solutions of generated games required to be unique -u

Game::Game() {

}

bool Game::read() {
    for(int i = 0;i < 9;i++)
        for(int j = 0;j < 9;j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == '$') {
                blank.push_back(i * 9 + j);
                sudoku[i][j] = 0;
                continue;
            }
            if(sudoku[i][j] >= '0' && sudoku[i][j] <= '9') continue;
            else return false;
        }
}

bool Game::find_blanks() {
    for(int i = 0;i < 9;i++)
        for(int j = 0;j < 9;j++){
            if(sudoku[i][j] == '$') {
                blank.push_back(i * 9 + j);
                sudoku[i][j] = 0;
                continue;
            }
            if(sudoku[i][j] >= '0' && sudoku[i][j] <= '9') continue;
            else return false;
        }
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
        if(available(blank[x] / 9, blank[x] % 9, i + '0')) {
            if (x != this->blank.size() - 1) { if (dfs(x + 1)) return true; }
            else { if (this->check()) return true; }
            sudoku[blank[x] / 9][blank[x] % 9] = 0;
        }
    }
    return false;
}

bool Game::dfs2(int x) {
    if(x < 0) return false;
    for(int i = 1;i < 10;i++) {
        if(available(blank[x] / 9, blank[x] % 9, i + '0')) {
            if (x > 0) {if(dfs2(x - 1)) return true; }
            else {if(this->check()) return true; }
            sudoku[blank[x] / 9][blank[x] % 9] = 0;
        }
    }
    return false;
}

bool Game::solve() {
    this->read();
    if(this->dfs(0)) print();
//    if(this->dfs2(blanks - 1)) print();
    else cout << "no answer!" << endl;

    return true;
}

void Game::print() {
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j ++)
            cout << this->sudoku[i][j] << ' ';
        cout << endl;
    }
}

void Game::generate_unique() {
    bool flag = true;
    while(flag) {
        generate();
        char ans1[100];
        dfs(0);
        for(int i = 0;i < blanks;i++) {
            ans1[i] = sudoku[blank[i] / 9][blank[i] % 9];
            sudoku[blank[i] / 9][blank[i] % 9] = 0;
        }
        dfs2(blanks - 1);
        flag = false;
        for(int i = 0;i < blanks;i++) {
            if(ans1[i] != sudoku[blank[i] / 9][blank[i] % 9]) {
                flag = true;
                break;
            }
        }
    }
}

bool Game::available(int x, int y, char ans) {
    if(sudoku[x][y] != 0) return false;
    for(int i = 0;i < 9;i++) {
        if(sudoku[x][i] == ans) return false;
        if(sudoku[i][y] == ans) return false;
        int grid_x = x / 3, grid_y = y / 3;
        for(int j = 0;j < 3;j++)
            for(int k = 0;k < 3;k++)
                if(sudoku[grid_x * 3 + j][grid_y * 3 + k] == ans) return false;
    }
    sudoku[x][y] = ans;
    return true;
}

void initXOrd(int* xOrd) {
    int i, k, tmp;
    for (i = 0; i < 9; i++)
        xOrd[i] = i;
    for (i = 0; i < 9; i++) {
        k = rand() % 9;
        tmp = xOrd[k];
        xOrd[k] = xOrd[i];
        xOrd[i] = tmp;
    }
}

bool Game::fillFrom(int y, int val) {
    int xOrd[9];
    initXOrd(xOrd);
    for (int i = 0; i < 9; i++) {
        int x = xOrd[i];
        if(available(y, x, val + '0')) {
            if(y == 8) {
                if(val == 9 || fillFrom(0, val + 1)) return true;
            }
            else if(fillFrom(y + 1, val)) return true;
            sudoku[y][x] = 0;
        }
    }
    return false;
}

void Game::generate() {
    // generate blanks
    bool is_used[100];
    memset(is_used, 0, sizeof(is_used));
    memset(sudoku, 0, sizeof(sudoku)); // initialize as 0s
    srand((unsigned) time(NULL));
    int tot = 0;
    while(tot < blanks) {
        int hashed_x = rand() % 81;
        if(!is_used[hashed_x]) {
            is_used[hashed_x] = true;
            this->blank.push_back(hashed_x);
            tot++;
        }
    }
//
//    // generate random first line
//    bool is_used2[10];
//    memset(is_used2, 0, sizeof(is_used));
//    for(int i = 0;i < 9;i++) {
//        int x = (rand() % 9) + 1;
//        if(is_used[x]) i-=1;
//        else {
//            this->sudoku[0][i] = x + '0';
//            is_used[x] = true;
//        }
//    }
//
//    // generate other lines according to the first line
//    for(int i = 1;i < 9;i++) {
//        for(int j = 0;j < 9;j++) {
//            char x = (rand() % 9) + '1';
//            if(!available(i, j, x)) j--;
//            else sudoku[i][j] = x;
//        }
//    }
    fillFrom(0, 1);
    for(int i = 0;i < blanks;i++) {
        sudoku[blank[i] / 9][blank[i] % 9] = '$';
    }
}