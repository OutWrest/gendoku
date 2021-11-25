#include "solver/backtrack.hpp"

Backtrack::Backtrack(const int num_of_solutions) : SolverBase(num_of_solutions) {
    // constructor
};

void Backtrack::solve(vector<vector<int>> board, void (* callback)(vector<vector<int>>)) {
    if (this->num_of_solutions <= this->num_of_solutions_found) {
        return;
    }

    return;
}