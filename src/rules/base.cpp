#include "rules/base.hpp"

RuleBase::RuleBase() {
}

RuleBase::~RuleBase() {
}

bool RuleBase::is_in_row(const vector<vector<int>> board, const int row, const int number) {
    for (int k = 0; k < board[row].size(); k++) {
        if (board[row][k] == number) {
            return true;
        }
    }

    return false;
}

bool RuleBase::is_in_col(const vector<vector<int>> board, const int col, const int number) {
    for (int k = 0; k < board.size(); k++) {
        if (board[k][col] == number) {
            return true;
        }
    }

    return false;
}

bool RuleBase::is_in_box(const vector<vector<int>> board, const int row, const int col, const int number) {
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == number) {
                return true;
            }
        }
    }

    return false;
}

vector<int> RuleBase::get_possible_vanilla(const vector<vector<int>> board, const int row, const int col) {
    vector<int> possible_numbers;

    // check if the cell is empty
    if (board[row][col] == 0) {
        for (int i = 1; i <= 9; i++) {
            // if the number is not in the row, column or 3x3 box
            if (!is_in_row(board, row, i) && !is_in_col(board, col, i) && !is_in_box(board, row, col, i)) {
                possible_numbers.push_back(i);
            }
        }
    }

    return possible_numbers;
}

vector<int> RuleBase::get_possbile(const vector<vector<int>> board, const int row, const int col) {
    return get_possible_vanilla(board, row, col);
}