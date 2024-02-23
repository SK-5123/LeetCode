class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        
        while (num <= n * n) {
            for (int i = left; i <= right && num <= n * n; ++i)
                matrix[top][i] = num++;
            ++top;
            
            for (int i = top; i <= bottom && num <= n * n; ++i)
                matrix[i][right] = num++;
            --right;
            
            for (int i = right; i >= left && num <= n * n; --i)
                matrix[bottom][i] = num++;
            --bottom;
            
            for (int i = bottom; i >= top && num <= n * n; --i)
                matrix[i][left] = num++;
            ++left;
        }
        return matrix;
    }
};