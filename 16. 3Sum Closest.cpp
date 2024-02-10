class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
          int closestSum = INT_MAX;
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }

                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    // Found exact match, return immediately
                    return target;
                }
            }
        }

        return closestSum;
    }
};