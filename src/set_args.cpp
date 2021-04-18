#include <iostream>
#include <sstream>
#include "../include/arguments.h"

using namespace std;

extern int count; // number of solved games, 1 <= count <= 10000000 -c
extern string path; // path -s
extern int number; // number of games to be generated, 1 <= number <= 10000 -n
extern int level; // difficulty level, 1 2 3 -m
extern int blanks; // number of blanks in the game to be filled, 20 <= blanks <= 55 -r
extern bool unique; // whether the solutions of generated games required to be unique -u

bool is_set[6]; // return false if exists redundant argument

bool is_digit(string str) {
    for (int i = 0;i < str.size();i++) {
        if (str.at(i) == '-' && str.size() > 1)  // 有可能出现负数
            continue;
        if (str.at(i) > '9' || str.at(i) < '0')
            return false;
    }
    return true;
}

bool set_arguments(int argc, char** argv) {
    string arguments[20];
    for(int i = 1;i < argc;i++) {
        arguments[i] = argv[i];
    }

    for(int i = 1;i < argc;i++) {
        if(arguments[i] == "-c") {
            if(is_set[0]) return false;
            is_set[0] = true;
            i += 1;
            if(!is_digit(arguments[i])) {
                cout << "error at -m " << arguments[i] << endl
                     << "this argument is supposed to be an integer!" << endl;
                return false;
            }
            stringstream ss;
            ss << arguments[i];
            ss >> count;
            if(count < 0 || count > 10000000) {
                cout << "error at -m " << arguments[i] << endl
                     << "this argument is supposed to be between 1 and 10000000!" << endl;
                return false;
            }

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