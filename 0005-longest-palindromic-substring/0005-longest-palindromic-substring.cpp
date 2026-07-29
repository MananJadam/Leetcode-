class Solution {
public:

    bool isPalindrome(string &s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }


    string longestPalindrome(string s) {

        string ans = "";

        for(int i = 0; i < s.size(); i++) {

            for(int j = i; j < s.size(); j++) {

                if(isPalindrome(s, i, j)) {

                    int length = j - i + 1;

                    if(length > ans.size()) {
                        ans = s.substr(i, length);
                    }
                }
            }
        }

        return ans;
    }
};