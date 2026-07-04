class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int cnt=0;
        // int n=nums.size();
        
        
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j =i;j<n;j++){
                
        //         sum+=nums[j];
        //         if(sum==k){
        //                 cnt++;
        //             }
        //     }
        // }return cnt;

        unordered_map<int,int> mpp;
        int presum=0;
        int cnt=0;
        mpp[0]=1;

        for(int i=0; i<nums.size(); i++){
            presum+=nums[i];
            int remove= presum-k;
            cnt+=mpp[remove];
            mpp[presum]+=1;




        }return cnt;




        
    }
};