#ifndef RULES_BASE_HPP
#define RULES_BASE_HPP

#include <vector>

class RuleBase {
public:
    // default constructor
    RuleBase();

    // default destructor
    virtual ~RuleBase();

    // get possible values for a cell using the board. returns a list of vectors
    virtual std::vector<std::vector<int>> getPossibleValues(const int** board, const int row, const int col) = 0;
};

#endif // RULES_BASE_HPP