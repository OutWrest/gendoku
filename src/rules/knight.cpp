#include <set>

#include "rules/knight.hpp"

KnightRule::KnightRule() {
    // default constructor
}

KnightRule::~KnightRule() {
    // default destructor
}

char* KnightRule::get_name() {
    return "Knight ruleset";
}

bool KnightRule::is_knight(const vector<vector<int>> board, const int row, const int col, const int number) {
    // top left knight move
    if (row - 2 >= 0 && col - 1 >= 0 && board[row - 2][col - 1] == number) {
        // cout << "top left knight move" << endl;
        return false;
    }

    // top right knight move
    if (row - 2 >= 0 && col + 1 < board[row].size() && board[row - 2][col + 1] == number) {
        // cout << "top right knight move" << endl;
        return false;
    }

    // left top knight move
    if (row - 1 >= 0 && col - 2 >= 0 && board[row - 1][col - 2] == number) {
        // cout << "left top knight move" << endl;
        return false;
    }

    // left bottom knight move
    if (row + 1 < board.size() && col - 2 >= 0 && board[row + 1][col - 2] == number) {
        // cout << "left bottom knight move" << endl;
        return false;
    }

    // right top knight move
    if (row - 1 >= 0 && col + 2 < board[row].size() && board[row - 1][col + 2] == number) {
        // cout << "right top knight move" << endl;
        return false;
    }

    // right bottom knight move
    if (row + 1 < board.size() && col + 2 < board[row].size() && board[row + 1][col + 2] == number) {
        // cout << "right bottom knight move" << endl;
        return false;
    }

    // bottom left knight move
    if (row + 2 < board.size() && col - 1 >= 0 && board[row + 2][col - 1] == number) {
        // cout << "bottom left knight move" << endl;
        return false;
    }

    // bottom right knight move
    if (row + 2 < board.size() && col + 1 < board[row].size() && board[row + 2][col + 1] == number) {
        // cout << "bottom right knight move" << endl;
        return false;
    }

    return true;
}

vector<int> KnightRule::get_possible(const vector<vector<int>> board, const int row, const int col) {
    vector<int> possible;

    for (int i = 1; i <= 9; i++) {
        // cout << "i: " << i << endl;
        if (is_knight(board, row, col, i)) {
            possible.push_back(i);
        }
    }

    return possible;
}