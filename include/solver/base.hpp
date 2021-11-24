#ifndef SOLVER_BASE_HPP
#define SOLVER_BASE_HPP

class SolverBase {
public:
    virtual ~SolverBase() = default;
    virtual void solve(int** board, bool (* callback)(int**)) = 0;
};

#endif