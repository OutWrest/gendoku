#include <iostream>
#include <vector>
#include <time.h>

#include "solver/backtrack.hpp"
#include "io/file.hpp"

#include "rules/knight.hpp"
#include "rules/adjacent.hpp"

using namespace std;

void print_board(vector<vector<int>> board) {
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
    FileIO fileio("output.txt");

    time_t start = time(0);
    Backtrack solver(1);
    
    vector<vector<int>> board {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    KnightRule kr;
    AdjacentRule ar;

    solver.add_rule(kr);
    solver.add_rule(ar);

    solver.solve(board, &fileio);

    double time_taken = difftime(time(0), start);

    printf("%d solutions found in %f seconds.\n", solver.get_num_of_solutions(), time_taken);

    vector<int> a = ar.get_possible(board, 0, 0);
    
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i] << " ";
    // }

    return 0;
}