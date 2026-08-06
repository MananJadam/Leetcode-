class Solution {
public:
    string removeKdigits(string num, int k) {
       stack<char> st;
        int n = num.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        
        while (k > 0) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string res = "";

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

       
        reverse(res.begin(), res.end());

        
        while (!res.empty() && res[0] == '0') {
            res.erase(res.begin());
        }

        if (res.empty())
            return "0";

        return res;
        
    }
};