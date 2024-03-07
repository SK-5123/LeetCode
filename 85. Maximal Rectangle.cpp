class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> heights(rows, vector<int>(cols, 0));
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = (i == 0) ? 1 : heights[i - 1][j] + 1;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            vector<int> stack;
            for (int j = 0; j <= cols; ++j) {
                int height = (j == cols) ? 0 : heights[i][j];
                while (!stack.empty() && height < heights[i][stack.back()]) {
                    int h = heights[i][stack.back()];
                    stack.pop_back();
                    int w = stack.empty() ? j : j - stack.back() - 1;
                    maxArea = max(maxArea, h * w);
                }
                stack.push_back(j);
            }
        }

        return maxArea;
    }
};