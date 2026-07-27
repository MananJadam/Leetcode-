class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        // int maxi = *max_element(nums.begin(), nums.end());

        // for(int divisor=1;divisor<=maxi;divisor++){
        //     int sum=0;

        //     for(int i=0; i<nums.size(); i++){
            

        //     sum+=ceil((double)nums[i]/divisor);

        //     }

        //     if(sum<=threshold){
        //        return divisor;
        //     }
            



        // }

        // return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low < high) {

            int mid = low + (high - low) / 2;

            int sum = 0;

            for (int num : nums)
                sum += (num + mid - 1) / mid;

            if (sum <= threshold)
                high = mid;
            else
                low = mid + 1;
        }

        return low;

    }
};