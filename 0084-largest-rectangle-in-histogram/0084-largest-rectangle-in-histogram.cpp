class Solution {
public:
    vector<int>pse(vector<int>&arr){
        int n=arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);

        
        }
        return pse;
    }
    vector<int>nse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;

            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
            
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int> psee = pse(heights);
        vector<int> nsee = nse(heights);
        int maxi=0;
        for(int i = 0; i < heights.size(); i++)
        {
            int width = nsee[i] - psee[i] - 1;
            int area = heights[i] * width;

            maxi = max(maxi, area);
        }
        return maxi;  
    }
};