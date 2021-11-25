#ifndef SOLVER_BACKTRACK_HPP
#define SOLVER_BACKTRACK_HPP

using namespace std;

#include <vector>
#include "solver/base.hpp"

class Backtrack : public SolverBase  {
public:
    // constructor, use parent
    Backtrack(const int num_of_solutions);

    // add rule
    void addRule(RuleBase& rule);

    // solver
    void solve(vector<vector<int>> board, FileIO* fileio) override;
};

#endif // SOLVER_BACKTRACK_HPP