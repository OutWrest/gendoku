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
    delete rules[0];
}

void SolverBase::add_rule(RuleBase& rule) {
    rules.push_back(&rule);
    cout << "Rule added: " << rule.get_name() << endl;
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
    set<int> prev_set;
    vector<int> prev_vec;

    set<int> next_set;
    vector<int> next_vec;
    
    vector<int> possible_numbers;

    if (board[i][j] == 0) {
        for (RuleBase* rule : rules) {
            // keep track of the previous set and only keep numbers that are in both sets
            if (prev_set.empty())
            {
                // first set
                prev_vec = rule->get_possible(board, i, j);

                for (int num : prev_vec) {
                    prev_set.insert(num);
                }
            }
            else {
                // next set
                next_vec = rule->get_possible(board, i, j);

                for (int num : next_vec) {
                    // if num in prev_set, add to next_set
                    if (prev_set.find(num) != prev_set.end()) {
                        next_set.insert(num);
                    }
                }

                // update prev_set
                prev_set = next_set;

                next_set.clear();
                next_vec.clear();
            }
        }
    }

    // convert set to vector
    for (int k : prev_set) {
        possible_numbers.push_back(k);
    }

    return possible_numbers;
}

int SolverBase::get_num_of_solutions() {
    return this->num_of_solutions_found;
}