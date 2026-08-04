class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;

        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (nums[i] > maxi)
                maxi = nums[i];
        }
        int minEle=*min_element(nums.begin(),nums.end());
        for (int i = minEle; i <= maxi; i++) {
            if (mp[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};