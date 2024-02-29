class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (existHelper(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
private:
    bool existHelper(vector<vector<char>>& board, const string& word, int index, int row, int col) {
        if (index == word.length()) return true;
        
        int m = board.size();
        int n = board[0].size();
        
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '*';         
        bool found = existHelper(board, word, index + 1, row + 1, col) ||
                     existHelper(board, word, index + 1, row - 1, col) ||
                     existHelper(board, word, index + 1, row, col + 1) ||
                     existHelper(board, word, index + 1, row, col - 1);
        
        board[row][col] = temp; 
        
        return found;
    }
};