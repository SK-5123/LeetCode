class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();
        int maxReachable = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i > maxReachable) 
                return false;
            maxReachable = std::max(maxReachable, i + nums[i]); 
            if (maxReachable >= n - 1) 
                return true;
        }
        
        return true;
    }
};