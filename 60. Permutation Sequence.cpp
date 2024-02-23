class Solution {
public:
    string getPermutation(int n, int k) {
         string result;
        vector<int> factorial(n, 1);
        vector<char> numbers;
        
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i + '0');
        }
        
        --k; 
        
        for (int i = n; i >= 1; --i) {
            int index = k / factorial[i - 1];
            result.push_back(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= factorial[i - 1];
        }
     return result;   
    }
};