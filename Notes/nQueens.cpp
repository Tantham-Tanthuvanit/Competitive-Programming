#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int>& board, int col, int row) {
	for (int c = 0; c < col; ++c) {
		if (board[c] == row) return false;
		if (abs(board[c] - row) == abs(c - col)) return false;
	}

	return true;
}

void solve(vector<int>& board, int col, int n, vector<vector<int>>& solutions) {
	if (col == n) {
		solutions.push_back(board);
		return;
	}
	for (int row = 0; row < n; ++row) {
		if (isSafe(board, col, row)) {
			board[col] = row;
			solve(board, col + 1, n, solutions);
			board[col] = -1;
		}
	}
}
