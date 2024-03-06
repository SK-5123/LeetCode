class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> s;
        int maxArea = 0;
        int i = 0;
        
        while (i < heights.size()) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i);
                i++;
            } else {
                int topIndex = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = std::max(maxArea, heights[topIndex] * width);
            }
        }
        
        while (!s.empty()) {
            int topIndex = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = std::max(maxArea, heights[topIndex] * width);
        }
        
        return maxArea;
    }
};