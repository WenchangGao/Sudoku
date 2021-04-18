#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#include <vector>

class Game {
    char sudoku[9][9]; // game board
    std::vector<int> blank; // hashed blanks
public:
    Game();
    bool solve();
    bool check();
    void generate();
    void generate_unique();
};


#endif //SUDOKU_GAME_H
