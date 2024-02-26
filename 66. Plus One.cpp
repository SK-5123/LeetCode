 int n = digits.size();
        int carry = 1; // Initialize carry to 1 as we are adding 1
        for (int i = n - 1; i >= 0; --i) { // Start from the least significant digit
            digits[i] += carry; // Add carry to the current digit
            carry = digits[i] / 10; // Determine the new carry
            digits[i] %= 10; // Update the current digit
        }
        
        if (carry) { // If there's still a carry after the loop, prepend it to the digits
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};
