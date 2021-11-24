#ifndef SOLVER_BASE_HPP
#define SOLVER_BASE_HPP

#include <vector>
#include "rules/base.hpp"

using namespace std;

class SolverBase {
    vector<RuleBase*> rules;
public:
    // constructor
    SolverBase();
    
    // destructor
    ~SolverBase();

    // add rule
    virtual void addRule(const RuleBase& rule) = 0;

    // solve
    virtual void solve(vector<vector<int>> board, bool (* callback)(vector<vector<int>>)) = 0;
};

#endif // SOLVER_BASE_HPP