class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int n=nums.size();
        // int maxlen=0;
        // for(int i=0; i<n;i++){
        //     int zeroes=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==0){
        //             zeroes++;
        //         }
        //         if(zeroes<=k){
        //             maxlen=max(maxlen, j-i+1);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxlen;
        int n=nums.size();
        int maxlen=0;
        int l=0;
        int r=0;
        int zeroes=0;
        while(r<n){
            if(nums[r]==0) zeroes++;
            while(zeroes>k){
                if(nums[l]==0)zeroes--;
                l++;
            }
            if(zeroes<=k){
                maxlen=max(maxlen,r-l+1);

            }
            r++;

        }
        return maxlen;
    }
};