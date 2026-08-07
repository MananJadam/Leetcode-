#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper to calculate how many digits are required to satisfy the remaining prime factors
    int get_required_length(int c2, int c3, int c5, int c7) {
        int length = c7 + c5;
        
        // Greedily pair 3s into 9s
        length += c3 / 2;
        c3 %= 2;
        
        // Greedily group 2s into 8s
        length += c2 / 3;
        c2 %= 3;
        
        // Handle remaining combinations of 2s and 3s
        if (c2 == 2 && c3 == 1) { 
            length += 2; // 12 -> 2 and 6 (2 digits)
        } else if (c2 == 2 && c3 == 0) { 
            length += 1; // 4 (1 digit)
        } else if (c2 == 1 && c3 == 1) { 
            length += 1; // 6 (1 digit)
        } else if (c2 == 1 && c3 == 0) { 
            length += 1; // 2 (1 digit)
        } else if (c2 == 0 && c3 == 1) { 
            length += 1; // 3 (1 digit)
        }
        return length;
    }

    // Helper to construct the smallest suffix string given the remaining slot count and required primes
    string construct_suffix(int slots, int c2, int c3, int c5, int c7) {
        string suffix = "";
        
        int count7 = c7;
        int count5 = c5;
        
        int count9 = c3 / 2; c3 %= 2;
        int count8 = c2 / 3; c2 %= 3;
        
        int count6 = 0, count4 = 0, count3 = c3, count2 = c2;
        
        if (c2 == 2 && c3 == 1) {       
            count6 = 1; count2 = 1; count3 = 0; count4 = 0;
        } else if (c2 == 2 && c3 == 0) { 
            count4 = 1; count2 = 0;
        } else if (c2 == 1 && c3 == 1) { 
            count6 = 1; count2 = 0; count3 = 0;
        }
        
        // Append all digits in ascending order to keep the number minimal
        suffix.append(count2, '2');
        suffix.append(count3, '3');
        suffix.append(count4, '4');
        suffix.append(count5, '5');
        suffix.append(count6, '6');
        suffix.append(count7, '7');
        suffix.append(count8, '8');
        suffix.append(count9, '9');
        
        // Pad with '1's at the front of the suffix to fill up the required slots
        int ones = slots - suffix.length();
        return string(ones, '1') + suffix;
    }

public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        
        if (temp > 1) return "-1";
        
        int n = num.length();
        // Find the first occurrence of '0'
        int first_zero = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }
        
        vector<int> c2(n + 1, 0), c3(n + 1, 0), c5(n + 1, 0), c7(n + 1, 0);
        c2[0] = req2; c3[0] = req3; c5[0] = req5; c7[0] = req7;
        
        // Only process the prefix up to the first '0'
        for (int i = 0; i < first_zero; ++i) {
            int d = num[i] - '0';
            int n2 = c2[i], n3 = c3[i], n5 = c5[i], n7 = c7[i];
            if (d == 2 || d == 6 || d == 8) n2 -= (d == 2 ? 1 : (d == 6 ? 1 : 3));
            if (d == 4) n2 -= 2;
            if (d == 3 || d == 6) n3 -= 1;
            if (d == 9) n3 -= 2;
            if (d == 5) n5 -= 1;
            if (d == 7) n7 -= 1;
            
            c2[i + 1] = max(0, n2);
            c3[i + 1] = max(0, n3);
            c5[i + 1] = max(0, n5);
            c7[i + 1] = max(0, n7);
        }
        
        // If no '0' exists and the original number is already valid
        if (first_zero == n && c2[n] == 0 && c3[n] == 0 && c5[n] == 0 && c7[n] == 0) {
            return num;
        }
        
        // Start backtracking from the first '0' position or the end of the string
        int start_idx = min(n - 1, first_zero);
        for (int i = start_idx; i >= 0; --i) {
            int start_digit = (num[i] == '0') ? 1 : (num[i] - '0' + 1);
            for (int d = start_digit; d <= 9; ++d) {
                int n2 = c2[i], n3 = c3[i], n5 = c5[i], n7 = c7[i];
                if (d == 2 || d == 6 || d == 8) n2 -= (d == 2 ? 1 : (d == 6 ? 1 : 3));
                if (d == 4) n2 -= 2;
                if (d == 3 || d == 6) n3 -= 1;
                if (d == 9) n3 -= 2;
                if (d == 5) n5 -= 1;
                if (d == 7) n7 -= 1;
                
                n2 = max(0, n2); n3 = max(0, n3); n5 = max(0, n5); n7 = max(0, n7);
                
                int rem_slots = n - 1 - i;
                if (get_required_length(n2, n3, n5, n7) <= rem_slots) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += construct_suffix(rem_slots, n2, n3, n5, n7);
                    return ans;
                }
            }
        }
        
        int target_len = max(n + 1, get_required_length(req2, req3, req5, req7));
        return construct_suffix(target_len, req2, req3, req5, req7);
    }
};