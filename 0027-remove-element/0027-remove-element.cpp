class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int j=n;
        int i=0;
        while(i<j){
            if(nums[i]==val){
                nums[i]=nums[j-1];
                j--;
            }
            else{
                i++;
            }
        }
       return j; 
    }
};