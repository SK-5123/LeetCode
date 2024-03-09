class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        int n = s1.size();
        unordered_map<string, bool> memo;
        return isScrambleHelper(s1, s2, memo);
    }

private:
    bool isScrambleHelper(const string& s1, const string& s2, unordered_map<string, bool>& memo) {
        string key = s1 + "-" + s2;
        if (memo.find(key) != memo.end()) return memo[key];

        int n = s1.size();
        if (n == 1) return s1 == s2;

        for (int i = 1; i < n; ++i) {
            if ((isScrambleHelper(s1.substr(0, i), s2.substr(0, i), memo) &&
                isScrambleHelper(s1.substr(i), s2.substr(i), memo)) ||
                (isScrambleHelper(s1.substr(0, i), s2.substr(n - i), memo) &&
                isScrambleHelper(s1.substr(i), s2.substr(0, n - i), memo))) {
                memo[key] = true;
                return true;
            }
        }

        memo[key] = false;
        return false;
    }
};