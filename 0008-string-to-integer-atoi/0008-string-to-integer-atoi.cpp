class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. Build number
        long long ans = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // 4. Check overflow
            if (sign * ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign * ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * ans;
    }
};