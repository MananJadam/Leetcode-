class Solution {
public:
    string reverseWords(string s) {
        string temp="";

        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(!temp.empty() && temp.back()!=' '){
                temp+=' ';
            }
        }

        if(!temp.empty() && temp.back()==' '){
            temp.pop_back();
        }

        reverse(temp.begin(), temp.end());

        int start=0;

        for(int i=0; i<=temp.size();i++){

            if(i==temp.size()|| temp[i]==' '){
                reverse(temp.begin()+start, temp.begin()+i);

                start=i+1;
            }
            

        }
        return temp;
        
    }
};