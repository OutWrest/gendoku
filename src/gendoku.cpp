#include <iostream>
#include <vector>

#include "solver/backtrack.hpp"
#include "io/file.hpp"

using namespace std;

void callback(vector<vector<int>> board) {
    // print the board
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    // Usage ./gendoku <how many to generate, -1 for all> <output file> -r <rules file>
    // Example ./gendoku -1 output.txt -r rules.txt

    // check if there are enough arguments
    // if (argc < 3) {
    //     printf("Usage ./gendoku <how many to generate, -1 for all> <output file> -r <rules file>\n");
    //     printf("Example ./gendoku -1 output.txt -r rules.txt\n");
    //     return 1;
    // }

    // // check if the output file exists
    // static FILE *f = fopen(argv[2], "r");

    // if (f != NULL) {
    //     printf("Output file already exists.\n");
    //     return 1;
    // }

    // check if the rules file exists
    // f = fopen(argv[4], "r");

    // if (f == NULL) {
    //     printf("Rules file does not exist.\n");
    //     return 1;
    // }

    // check if the rules file is empty
    // fseek(f, 0, SEEK_END);
    // int size = ftell(f);
    // fseek(f, 0, SEEK_SET);

    // if (size == 0) {
    //     printf("Rules file is empty.\n");
    //     return 1;
    // }

    // create a new solver
    Backtrack solver(1);
    FileIO fileio("output.txt");
    
    vector<vector<int>> board {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solver.solve(board, &fileio);

    return 0;
}