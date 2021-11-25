#include <set>

#include "rules/knight.hpp"

KnightRule::KnightRule() {
    // default constructor
}

KnightRule::~KnightRule() {
    // default destructor
}

bool KnightRule::is_knight(const vector<vector<int>> board, const int row, const int col, const int number) {
    // top left knight move
    if (row - 2 >= 0 && col - 1 >= 0 && board[row - 2][col - 1] == number) {
        return false;
    }

    // top right knight move
    if (row - 2 >= 0 && col + 1 < board[row].size() && board[row - 2][col + 1] == number) {
        return false;
    }

    // left top knight move
    if (row - 1 >= 0 && col - 2 >= 0 && board[row - 1][col - 2] == number) {
        return false;
    }

    // left bottom knight move
    if (row + 1 < board.size() && col - 2 >= 0 && board[row + 1][col - 2] == number) {
        return false;
    }

    // right top knight move
    if (row - 1 >= 0 && col + 2 < board[row].size() && board[row - 1][col + 2] == number) {
        return false;
    }

    // right bottom knight move
    if (row + 1 < board.size() && col + 2 < board[row].size() && board[row + 1][col + 2] == number) {
        return false;
    }

    // bottom left knight move
    if (row + 2 < board.size() && col - 1 >= 0 && board[row + 2][col - 1] == number) {
        return false;
    }

    // bottom right knight move
    if (row + 2 < board.size() && col + 1 < board[row].size() && board[row + 2][col + 1] != number) {
        return false;
    }

    return true;
}

vector<int> KnightRule::get_possible(const vector<vector<int>> board, const int row, const int col) {
    vector<int> possible;

    for (int i = 1; i <= 9; i++) {
        if (is_knight(board, row, col, i)) {
            possible.push_back(i);
        }
    }

    return possible;
}