#include <iostream>

using namespace std;

extern int count; // number of solved games, 1 <= count <= 10000000 -c
extern string path; // path -s
extern int number; // number of games to be generated, 1 <= number <= 10000 -n
extern int level; // difficulty level, 1 2 3 -m
extern int blanks; // number of blanks in the game to be filled, 20 <= blanks <= 55 -r
extern bool unique; // whether the solutions of generated games required to be unique -u

// fuctions to be used, implemented in other .cpp files under directory src
bool set_arguments(int argc, char** argv);
bool solve_sudokus();
bool generate_sudokus();

int main(int argc, char** argv) {

    // set arguments, report errors if failed
    if(!set_arguments(argc, argv)) {
        cout << "setting arguments fatal!" << endl;
        return -1;
    }

    // solve puzzles, report errors if failed
    if(!solve_sudokus()) {
        cout << "failed to solve sudokus!" << endl;
        return -1;
    }

    // generate puzzles, report errors if failed
    if(!generate_sudokus()) {
        cout << "failed to generate sudokus!" << endl;
        return -1;
    }

    cout << unique << endl;
}