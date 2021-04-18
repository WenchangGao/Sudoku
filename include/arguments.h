#ifndef SUDOKU_ARGUMENTS_H
#define SUDOKU_ARGUMENTS_H

#include <string>

int count = 1; // number of solved games, 1 <= count <= 10000000
std::string path = "../tests/test.txt"; // path
int number = 1; // number of games to be generated, 1 <= number <= 10000
int level = 1; // difficulty level, 1 2 3
int blanks = 20; // number of blanks in the game to be filled, 20 <= blanks <= 55
bool unique = false; // whether the solutions of generated games required to be unique

#endif //SUDOKU_ARGUMENTS_H