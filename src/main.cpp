#include <iostream>

using namespace std;

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

}