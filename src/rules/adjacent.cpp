#include <set>

#include "rules/adjacent.hpp"

AdjacentRule::AdjacentRule() {
    // default constructor
}

AdjacentRule::~AdjacentRule() {
    // default destructor
}

char* AdjacentRule::get_name() {
    return "Adjacent ruleset";
}

bool AdjacentRule::is_adjacent(const vector<vector<int>> board, const int row, const int col, const int number) {
    // if there is a consecutive number adjacent to the number, return false

    // top
    if ((row - 1 >= 0 && board[row - 1][col] == max(number - 1, 1)) || (row - 1 >= 0 && board[row - 1][col] == min(number + 1, 9))) {
        // cout << "top" << endl;
        return false;
    }

    // right
    if ((col + 1 < board[row].size() && board[row][col + 1] == max(number - 1, 1)) || (col + 1 < board[row].size() && board[row][col + 1] == min(number + 1, 9))) {
        // cout << "right" << endl;
        return false;
    }

    // left
    if ((col - 1 >= 0 && board[row][col - 1] == max(number - 1, 1)) || (col - 1 >= 0 && board[row][col - 1] == min(number + 1, 9))) {
        // cout << "left" << endl;
        return false;
    }

    // bottom
    if ((row + 1 < board.size() && board[row + 1][col] == max(number - 1, 1)) || (row + 1 < board.size() && board[row + 1][col] == min(number + 1, 9))) {
        // cout << "bottom" << endl;
        return false;
    }

    return true;
}

vector<int> AdjacentRule::get_possible(const vector<vector<int>> board, const int row, const int col) {
    vector<int> possible;

    for (int i = 1; i <= 9; i++) {
        if (is_adjacent(board, row, col, i)) {
            possible.push_back(i);
        }
    }

    return possible;
}