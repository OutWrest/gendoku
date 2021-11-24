#ifndef SOLVER_BACKTRACK_HPP
#define SOLVER_BACKTRACK_HPP

#include "solver/base.hpp"

class Backtrack: virtual public SolverBase  {
public:
    // constructor
    Backtrack();

    // destructor
    ~Backtrack() override = default;

    // solver
    void solve(int** board, bool (* callback)(int**)) override;
};

#endif