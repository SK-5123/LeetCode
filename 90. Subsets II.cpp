class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        generateSubsets(nums, 0, subset, result);
        return result;
    }
    
private:
    void generateSubsets(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset); 
        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) 
                continue;
            
            subset.push_back(nums[i]);
            generateSubsets(nums, i + 1, subset, result); 
            subset.pop_back();
        }
    }
};