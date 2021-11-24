#ifndef SOLVER_BACKTRACK_HPP
#define SOLVER_BACKTRACK_HPP

using namespace std;

#include <vector>

#include "solver/base.hpp"

class Backtrack : SolverBase  {
    
public:
    // constructor
    Backtrack();

    // solver
    void solve(vector<vector<int>> board, bool (* callback)(vector<vector<int>>)) override;
};

#endif // SOLVER_BACKTRACK_HPP