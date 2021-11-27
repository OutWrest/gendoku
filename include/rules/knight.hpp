#ifndef RULES_KNIGHT_HPP
#define RULES_KNIGHT_HPP

using namespace std;

#include <vector>

#include "rules/base.hpp"

class KnightRule : public RuleBase {
public:
    // default constructor
    KnightRule();

    // default destructor
    ~KnightRule();

    // get the rule name
    char* get_name() override;

    // is knight
    bool is_knight(const vector<vector<int>> board, const int row, const int col, const int number);

    // override get_possbile
    vector<int> get_possible(const vector<vector<int>> board, const int row, const int col) override;
};

#endif // RULES_KNIGHT_HPP