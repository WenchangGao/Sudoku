#include <iostream>
#include "../include/Game.h"
#include "../include/arguments.h"

using namespace std;

extern int count; // number of solved games, 1 <= count <= 10000000
extern string path; // path
extern int number; // number of games to be generated, 1 <= number <= 10000
extern int level; // difficulty level, 1 2 3
extern int blanks; // number of blanks in the game to be filled, 20 <= blanks <= 55
extern bool unique; // whether the solutions of generated games required to be unique

bool set_arguments(int argc, char** argv);

int main(int argc, char** argv) {

}