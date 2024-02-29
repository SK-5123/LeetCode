class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        combineHelper(n, k, 1, current, result);
        return result;
    }
    
private:
    void combineHelper(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i <= n; ++i) {
            current.push_back(i);
            combineHelper(n, k - 1, i + 1, current, result);
            current.pop_back();
        }

    }
};