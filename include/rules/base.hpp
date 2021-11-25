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

    // get the rule name
    virtual char* get_name();

    // is in row
    bool is_in_row(const vector<vector<int>> board, const int row, const int number);

    // is in column
    bool is_in_col(const vector<vector<int>> board, const int col, const int number);

    // is in box
    bool is_in_box(const vector<vector<int>> board, const int row, const int col, const int number);

    // get possible values for a cell using the board. returns a list of vectors
    vector<int> get_possible_vanilla(vector<vector<int>> board, const int row, const int col);

    // get possible values (override)
    virtual vector<int> get_possible(vector<vector<int>> board, const int row, const int col);
};

#endif // RULES_BASE_HPP