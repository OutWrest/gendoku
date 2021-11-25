#include "solver/backtrack.hpp"

Backtrack::Backtrack(const int num_of_solutions) : SolverBase(num_of_solutions) {
    // constructor
};

void Backtrack::solve(vector<vector<int>> board, FileIO* fileio) {
    // check if the board is solved
    if (this->is_solved(board)) {
        this->num_of_solutions_found++;
        fileio->write(board);
        return;
    }

    if (this->num_of_solutions <= this->num_of_solutions_found) {
        return;
    }

    // find an empty cell
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0 && this->num_of_solutions_found < this->num_of_solutions) {
                
                // get all possible numbers for the cell
                vector<int> possible_numbers = this->get_possible_numbers(board, i, j);

                // try all possible numbers
                for (int k : possible_numbers) {
                    board[i][j] = k;

                    // if solved, then call the fileio callback
                    if (this->is_solved(board)) {
                        this->num_of_solutions_found++;
                        fileio->write(board);
                    }
                    else {
                        // solve the board
                        this->solve(board, fileio);
                    }

                    // reset the cell
                    board[i][j] = 0;
                }

                return;
            }
        }
    }

    return;
}