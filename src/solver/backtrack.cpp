#include "solver/backtrack.hpp"

Backtrack::Backtrack(const unsigned int num_of_solutions, const unsigned int num_of_threads = 1) : SolverBase(num_of_solutions, num_of_threads) {
    // constructor
};

void Backtrack::solve(vector<vector<int>> board, FileIO* fileio) {
    // check if the board is solved
    if (this->is_solved(board)) {
        this->num_of_solutions_found++;
        fileio->write(this->num_of_solutions_found - 1, board);
        return;
    }

    if (this->num_of_solutions <= this->num_of_solutions_found && this->num_of_solutions != 0) {
        return;
    }

    // find an empty cell
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0 && (this->num_of_solutions_found < this->num_of_solutions || this->num_of_solutions == 0)) {
                
                // get all possible numbers for the cell
                vector<int> possible_numbers = this->get_possible_numbers(board, i, j);

                // try all possible numbers
                for (int k : possible_numbers) {
                    board[i][j] = k;

                    // if solved, then call the fileio callback
                    if (this->is_solved(board)) {
                        this->num_of_solutions_found++;
                        fileio->write(this->num_of_solutions_found - 1, board);

                        if (this->num_of_solutions <= this->num_of_solutions_found && this->num_of_solutions != 0) {
                            return;
                        }
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