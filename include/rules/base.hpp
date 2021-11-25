#ifndef RULES_BASE_HPP
#define RULES_BASE_HPP

using namespace std;

#include <vector>

class RuleBase {
public:
    // default constructor
    RuleBase();

    // default destructor
    ~RuleBase();

    // get possible values for a cell using the board. returns a list of vectors
    virtual vector<int> getPossible(vector<vector<int>> board, int row, int col) = 0;
};

#endif // RULES_BASE_HPP