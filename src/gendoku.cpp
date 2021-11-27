#include <iostream>
#include <vector>
#include <time.h>
#include <string.h>

#include "solver/backtrack.hpp"
#include "io/file.hpp"

#include "rules/base.hpp"
#include "rules/knight.hpp"
#include "rules/adjacent.hpp"

using namespace std;

void print_board(vector<vector<int>> board) {
    // print the board
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vector<vector<int>> read_board(const char* filename) {
    vector<vector<int>> board;

    // open file
    FILE* file = fopen(filename, "r");

    // read file
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // split line
        vector<int> row;
        char* token = strtok(line, ",");

        while (token != NULL) {
            row.push_back(atoi(token));
            token = strtok(NULL, ",");
        }

        // add row to board
        board.push_back(row);
    }

    // close file
    fclose(file);

    return board;
}

int main(int argc, char *argv[]) {
    // Usage ./gendoku <how many to generate> <output file> -r <k|a|ka> -b (board.txt, optional)
    // Example ./gendoku 1 output.txt -r ka -b board.txt

    // check if there are enough arguments
    if (argc < 3) {
        printf("Usage: ./gendoku <how many to generate, default = 0> <output file> -r <k|a|ka> -b <board to start with, optional>\n");
        printf("Example: ./gendoku 1 output.txt -r ka -b board.txt\n");
        return 0;
    }

    // Parse board in txt file
    vector<vector<int>> board;

    if (argc > 4 && strcmp(argv[3], "-b") == 0) {
        board = read_board(argv[4]);

        // check if board is valid
        if (board.size() != 9 || board[0].size() != 9) {
            printf("Board is not valid\n");
            return 0;
        }

        printf("Loaded board:\n");
        print_board(board);
    }
    else {
        board = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
    }

    // create a new solver
    FileIO fileio(argv[2]);

    time_t start = time(0);
    Backtrack solver(atoi(argv[1]));

    // split the rules
    if (argc > 4 && strcmp(argv[4], "-r") == 0) {
        if (strcmp(argv[5], "k") == 0) {
            KnightRule kr;

            solver.add_rule(kr);
        }
        else if (strcmp(argv[5], "a") == 0) {
            AdjacentRule ar;

            solver.add_rule(ar);
        }
        else if (strcmp(argv[5], "ka") == 0) {
            KnightRule kr;
            AdjacentRule ar;

            solver.add_rule(kr);
            solver.add_rule(ar);
        }
    }

    // solve the puzzle
    solver.solve(board, &fileio);

    double time_taken = difftime(time(0), start);

    printf("%d solutions found in %f seconds.\n", solver.get_num_of_solutions(), time_taken);

    return 0;
}