class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (seen.find(board[i][j]) != seen.end())
                        return false;
                    seen.insert(board[i][j]);
                }
            }
        }
        
        // Check columns
        for (int j = 0; j < 9; ++j) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.') {
                    if (seen.find(board[i][j]) != seen.end())
                        return false;
                    seen.insert(board[i][j]);
                }
            }
        }
        
        // Check sub-boxes
        for (int k = 0; k < 9; ++k) {
            unordered_set<char> seen;
            int start_row = (k / 3) * 3;
            int start_col = (k % 3) * 3;
            for (int i = start_row; i < start_row + 3; ++i) {
                for (int j = start_col; j < start_col + 3; ++j) {
                    if (board[i][j] != '.') {
                        if (seen.find(board[i][j]) != seen.end())
                            return false;
                        seen.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};