#include "../include/arguments.h"
#include <iostream>

using namespace std;

extern int count; // number of solved games, 1 <= count <= 10000000 -c
extern string path; // path -s
extern int number; // number of games to be generated, 1 <= number <= 10000 -n
extern int level; // difficulty level, 1 2 3 -m
extern int blanks; // number of blanks in the game to be filled, 20 <= blanks <= 55 -r
extern bool unique; // whether the solutions of generated games required to be unique -u

bool is_set[6]; // return false if exists redundant argument

bool set_arguments(int argc, char** argv) {
    string arguments[20];
    for(int i = 0;i < argc;i++)
        arguments[i] = argv[i];
    for(int i = 0;i < argc;i++) {
        if(arguments[i] == "-c") {
            if(is_set[0]) return false;
            is_set[0] = true;


        }

        if(arguments[i] == "-s") {
            if(is_set[1]) return false;
            is_set[1] = true;


        }

        if(arguments[i] == "-n") {
            if(is_set[2]) return false;
            is_set[2] = true;


        }

        if(arguments[i] == "-m") {
            if(is_set[3]) return false;
            is_set[3] = true;


        }

        if(arguments[i] == "-r") {
            if(is_set[4]) return false;
            is_set[4] = true;


        }

        if(arguments[i] == "-u") {
            if(is_set[5]) return false;
            is_set[5] = true;


        }
    }
    return true;
}