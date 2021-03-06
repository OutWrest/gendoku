#ifndef RULES_ADJACENT_HPP
#define RULES_ADJACENT_HPP

using namespace std;

#include <vector>

#include "rules/base.hpp"

class AdjacentRule : public RuleBase {
public:
    // default constructor
    AdjacentRule();

    // default destructor
    ~AdjacentRule();

    // get the rule name
    char* get_name() override;

    // is adjacent
    bool is_adjacent(const vector<vector<int>> board, const int row, const int col, const int number);

    // override get_possbile
    vector<int> get_possible(const vector<vector<int>> board, const int row, const int col) override;
};

#endif // RULES_ADJACENT_HPP