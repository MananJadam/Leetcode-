class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> st;
        int area=0;
        int n = nums.size();
        for(int i=0;i<=nums.size();i++){
            int curr= i==n?0:nums[i];
            while(!st.empty() && nums[st.top()]>curr){
                int index=st.top();
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                area=max(area,width*nums[index]);
            }
            st.push(i);
            
        }
        return area;
    }
};