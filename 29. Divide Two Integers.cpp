class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == 1)
            return dividend;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

         long long dividendPositive = labs(dividend);
        long long divisorPositive = labs(divisor);
        
        long long quotient = 0;
        
        while (dividendPositive >= divisorPositive) {
            long long temp = divisorPositive, multiple = 1;
            while (dividendPositive >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dividendPositive -= temp;
            quotient += multiple;
        }
        
        quotient *= sign;
        
        if (quotient > INT_MAX)
            return INT_MAX;
        else if (quotient < INT_MIN)
            return INT_MIN;
        else
            return static_cast<int>(quotient);
    }
};