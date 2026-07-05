class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        list<int> lt;

        for (int i = 0; i < n; i++) {

            if (lt.size() == 0 || lt.front() != nums[i]) {
                int cnt = 0;

                for (int j = 0; j < n; j++) {
                    if (nums[i] == nums[j]) {
                        cnt++;
                    }
                }

                if (cnt > n / 3) {
                    lt.push_back(nums[i]);
                }
            }

            if (lt.size() == 2) {
                break;
            }
        }

        return vector<int>(lt.begin(), lt.end());
    }
};