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
    bool dfs(int x);
    void print();
    bool read();
    bool find_blanks();
    void reset(int x, int y);
    bool fillFrom(int y, int val);
    bool available(int x, int y, char ans);
    void generate();
    void generate_unique();
};


#endif //SUDOKU_GAME_H
