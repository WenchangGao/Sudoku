#include <iostream>
#include <fstream>
#include <stdio.h>
#include "../include/Game.h"

using namespace std;

extern int count; // number of solved games, 1 <= count <= 10000000 -c
extern string path; // path -s
extern int number; // number of games to be generated, 1 <= number <= 10000 -n
extern int level; // difficulty level, 1 2 3 -m
extern int blanks; // number of blanks in the game to be filled, 20 <= blanks <= 55 -r
extern bool unique; // whether the solutions of generated games required to be unique -u

int n;

bool solve_sudokus() {
    freopen(path.c_str(), "r", stdin);
    cin >> n;
    if(n < 0) return false;
    for(int i = 0;i < n;i++) {
        Game g;
        if(!g.solve()) return false;
    }
    cout << "solved successfully" << endl;
    return true;
}