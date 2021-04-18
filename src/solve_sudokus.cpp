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

bool solve_sudokus() {
    freopen(path.c_str(), "r", stdin);
    for(int i = 1;i <= count;i++) {
        Game g;
        cout << "Game # " << i << ":" << endl;
        if(!g.solve()) return false;
        cout << endl << endl;
    }
    cout << "solved successfully" << endl;
    return true;
}