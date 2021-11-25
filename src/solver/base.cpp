#include <set>

#include "solver/base.hpp"
#include "rules/base.hpp"

// constructor
SolverBase::SolverBase(const int num_of_solutions) {
    // initialize 
    rules = vector<RuleBase*>();
    this->num_of_solutions = num_of_solutions;
    this->num_of_solutions_found = 0;

    rules.push_back(new RuleBase());
}

// destructor
SolverBase::~SolverBase() {
    for (RuleBase* rule : rules) {
        delete rule;
    }
}

void SolverBase::addRule(RuleBase& rule) {
    rules.push_back(&rule);
}

bool SolverBase::is_solved(vector<vector<int>> board) {
    // check if the board is solved
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

vector<int> SolverBase::get_possible_numbers(const vector<vector<int>> board, const int i, const int j) {
    // check if the cell is empty
    set<int> possible_numbers_set;
    set<int> tmp;
    vector<int> tmp_v;

    vector<int> possible_numbers;

    if (board[i][j] == 0) {
        for (RuleBase* rule : rules) {
            // if possible_numbers is empty, then add all possible numbers
            tmp_v = rule->get_possbile(board, i, j);

            if (possible_numbers_set.empty()) {
                for (int k : tmp_v) {
                    possible_numbers_set.insert(k);
                }
            } else {
                // if possible_numbers is not empty, then intersect the two sets
                for (int k : tmp_v) {
                    tmp.insert(k);
                }

                for (int k : possible_numbers_set) {
                    if (tmp.find(k) != tmp.end()) {
                        possible_numbers_set.insert(k);
                    }
                }

                tmp.clear();
            }
        }
    }

    // convert set to vector
    for (int k : possible_numbers_set) {
        possible_numbers.push_back(k);
    }

    return possible_numbers;
}