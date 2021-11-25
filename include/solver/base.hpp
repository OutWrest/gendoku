#ifndef SOLVER_BASE_HPP
#define SOLVER_BASE_HPP

using namespace std;

#include <vector>

#include "rules/base.hpp"
#include "io/file.hpp"

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
    void add_rule(RuleBase& rule);

    // is solved
    bool is_solved(vector<vector<int>> board);

    // get all possible numbers for a cell using the rules
    vector<int> get_possible_numbers(vector<vector<int>> board, int i, int j);

    int get_num_of_solutions();

    // solve
    virtual void solve(vector<vector<int>> board, FileIO* fileio) = 0;
};

#endif // SOLVER_BASE_HPP