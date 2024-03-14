class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        backtrack(result, s, current, 0, 0);
        return result;
    }
    
    void backtrack(vector<string>& result, const string& s, string& current, int startIndex, int parts) {
        if (startIndex == s.size() && parts == 4) {
            result.push_back(current);
            return;
        }
        
        if (parts >= 4) {
            return;
        }
        
        for (int i = 1; i <= 3; ++i) {
            if (startIndex + i > s.size()) {
                break;
            }
            
            string part = s.substr(startIndex, i);
            if ((part[0] == '0' && part.size() > 1) || stoi(part) > 255) {
                break;
            }
            
            if (parts < 3) {
                part += ".";
            }
            
            current += part;
            backtrack(result, s, current, startIndex + i, parts + 1);
            current.resize(current.size() - part.size());
        }
    }
};