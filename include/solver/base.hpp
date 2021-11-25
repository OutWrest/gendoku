#ifndef SOLVER_BASE_HPP
#define SOLVER_BASE_HPP

#include <vector>
#include "rules/base.hpp"

using namespace std;

class SolverBase {
public:
    vector<RuleBase*> rules;
    int num_of_solutions;
    int num_of_solutions_found;

    // constructor
    SolverBase(const int num_of_solutions);

    // destructor
    ~SolverBase();

    // add rule
    void addRule(RuleBase& rule);

    // solve
    virtual void solve(vector<vector<int>> board, void (* callback)(vector<vector<int>>)) = 0;
};

#endif // SOLVER_BASE_HPP