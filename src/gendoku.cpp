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

struct config
{
    int numToSolve = 0;
    char* outputFilename = "output.txt";
    char* inputFilename;
    char* rulesList;
};

vector<vector<int>> read_board(const char* filename) {
    vector<vector<int>> board;

    // open file
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error board opening file\n");
        exit(1);
    }

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

void read_args(int argc, char* argv[], config* cfg) {
    // read arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            cfg->numToSolve = atoi(argv[i + 1]);
        } else if (strcmp(argv[i], "-o") == 0) {
            cfg->outputFilename = argv[i + 1];
        } else if (strcmp(argv[i], "-i") == 0) {
            cfg->inputFilename = argv[i + 1];
        } else if (strcmp(argv[i], "-r") == 0) {
            cfg->rulesList = argv[i + 1];
        }
    }
}

int main(int argc, char *argv[]) {
    // Usage ./gendoku <how many to generate> <output file> -r <k|a|ka> -b (board.txt, optional)
    // Example ./gendoku 1 output.txt -r ka -b board.txt

    // check if there are enough arguments
    if (argc < 2) {
        printf("Usage: ./gendoku <how many to generate, default = 0> --o <output file, optional> --r <k|a|ka, optional> --b <board to start with, optional>\n");
        printf("Example: ./gendoku -n 1 output.txt --r ka --b board.txt\n");
        return 0;
    }

    // get user arguments
    config cfg;
    
    read_args(argc, argv, &cfg);

    // read board
    vector<vector<int>> board = {
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

    if (cfg.inputFilename != NULL) {
        board = read_board(cfg.inputFilename);
    }

    // output file
    FileIO fileio(cfg.outputFilename);
    

    // create solver
    Backtrack solver(cfg.numToSolve);

    // default rules
    RuleBase rb;
    solver.add_rule(rb);

    // for character in rules list
    if (cfg.rulesList != NULL) {
        for (int i = 0; i < strlen(cfg.rulesList); i++) {
            char c = cfg.rulesList[i];

            // if character is k
            if (c == 'k') {
                KnightRule kr;
                solver.add_rule(kr);
            } else if (c == 'a') {
                AdjacentRule ar;
                solver.add_rule(ar);
            }
        }
    }

    printf("Started solving for %d boards...\n", cfg.numToSolve);

    time_t start = clock();

    // solve the puzzle
    solver.solve(board, &fileio);

    float time_taken = (clock () - start) /  CLOCKS_PER_SEC;

    printf("%d solutions found in %.2f seconds.\n", solver.get_num_of_solutions(), time_taken);

    return 0;
}

