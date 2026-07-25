class Solution {
public:
    int strStr(string haystack, string needle) {

        // int i=0;
        // int j=0;


        // while(i==haystack.size() && j==needle.size()){

        //     if(haystack[i]!=needle[j]){
        //         i++;
        //     }
        //     else if(haystack[i]==needle[j]){

        //         i++;
        //         j++;
        //         if(haystack[i]==needle[j]){
        //             return i-1;

        //         }
        //         else{
        //             j--;
        //         }
        //     }

     


            
        // }
        // return -1;

        int n=haystack.size();
        int m=needle.size();

        for(int i=0; i<=n-m;i++){
            bool mark=true;
            for(int j=0; j<m;j++){

                if(i+j==n||haystack[i+j]!=needle[j]){
                   mark=false;
                  

                }


            }
            if(mark) return i;
        }
        return -1;
    
    }
};