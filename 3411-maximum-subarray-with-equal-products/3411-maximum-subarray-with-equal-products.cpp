class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {

            long long prod = 1;
            long long hcf = nums[i];
            long long lcm = nums[i];

            for(int j = i; j < n; j++) {

                if(prod > 25200 / nums[j])
                    prod = 25201;
                else
                    prod *= nums[j];

                hcf = gcd(hcf, (long long)nums[j]);

                lcm = (lcm / gcd(lcm, (long long)nums[j])) * nums[j];

                if(prod == hcf * lcm) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }
};