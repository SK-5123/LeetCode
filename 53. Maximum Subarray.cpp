class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
    
private:
    int maxSubArrayHelper(const std::vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        int leftMax = maxSubArrayHelper(nums, left, mid);
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);
        int crossingMax = maxCrossingSubArray(nums, left, mid, right);
        
        return std::max({leftMax, rightMax, crossingMax});
    }
    
    int maxCrossingSubArray(const std::vector<int>& nums, int left, int mid, int right) {
        int leftSum = std::numeric_limits<int>::min();
        int rightSum = std::numeric_limits<int>::min();
        
        int sum = 0;
        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            leftSum = std::max(leftSum, sum);
        }
        
        sum = 0;
        for (int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            rightSum = std::max(rightSum, sum);
        }
        
        return leftSum + rightSum;
    }
};