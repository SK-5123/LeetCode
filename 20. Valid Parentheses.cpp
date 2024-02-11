class Solution {
    public:
        bool isValid(string s) {
            stack<char> parentheses;
            for (char& c : s) {
                if (c == '(' || c == '{' || c == '[') {
                    parentheses.push(c);
                } else {
                    if (parentheses.empty()) return false;
                    char top = parentheses.top();
                    parentheses.pop();
                    if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                        return false;
                    }
                }
            }
            return parentheses.empty();
        }
    };