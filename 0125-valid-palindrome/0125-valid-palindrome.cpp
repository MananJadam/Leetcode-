class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(int i=0; i<s.length();i++){
            if(isalnum(s[i])){
                t+=tolower(s[i]);
            }
        }
        int i=0;
        int j=t.length()-1;
        while(i<j){
            if(t[i]!=t[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;

    }
};