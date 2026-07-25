class Solution {
public:
    int mySqrt(int x) {
        int ans=1;
        if(x==0)return 0;
        for(int i=1; i<=x; i++ ){
            if(i<=x/i){
                ans=i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};