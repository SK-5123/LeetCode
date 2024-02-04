class Solution {
public:
    bool isPalindrome(int x) {
        unsigned int a, rev = 0, last;
        a= x;
        while (a>0){
        last = a%10;
        rev = rev*10 +last;
        a = a/10;
    }
    return rev ==x;
    }
    
};