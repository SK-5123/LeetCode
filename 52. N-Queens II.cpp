class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<int> positions(n, -1); 
        solveNQueens(0, n, positions, count);
        return count;
    }
    private:
    void solveNQueens(int row, int n, std::vector<int>& positions, int& count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, positions)) {
                positions[row] = col;
                solveNQueens(row + 1, n, positions, count);
                positions[row] = -1;
            }
        }
    }

    bool isValid(int row, int col, const std::vector<int>& positions) {
        for (int i = 0; i < row; ++i) {
            if (positions[i] == col ||              
                std::abs(row - i) == std::abs(col - positions[i])) { 
                return false;
            }
        }
        return true;

    }
};