class Solution {
public:
    int reverse(int x) {
        long int num = 0;
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            num = num * 10 + digit;
            
            if (num >= 2147483647 || num <= -2147483647) // Check for overflow
                return 0;
        }
        
        return int(num);
    }
};
