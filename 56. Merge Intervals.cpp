class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergedIntervals;
        
        for (const auto& interval : intervals) {
            if (mergedIntervals.empty() || interval[0] > mergedIntervals.back()[1]) {
                mergedIntervals.push_back(interval);
            } else {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            }
        }
        
        return mergedIntervals;
    }
};