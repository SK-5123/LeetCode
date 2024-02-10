class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        backtrack(digits, 0, "", result, mapping);
        
        return result;
    }
    
    void backtrack(const string& digits, int index, string current, vector<string>& result, const vector<string>& mapping) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for (char c : mapping[digit]) {
            backtrack(digits, index + 1, current + c, result, mapping);
        }
    }
};