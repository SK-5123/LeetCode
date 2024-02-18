class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
        if (n <= 2) return 0;
        int left = 0, right = n - 1; 
        int leftMax = 0, rightMax = 0; 
        int water = 0; 
        while (left < right) {
            leftMax = std::max(leftMax, height[left]);
            rightMax = std::max(rightMax, height[right]);
            
            if (leftMax < rightMax) {
                water += leftMax - height[left];
                left++;
            } else {
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};