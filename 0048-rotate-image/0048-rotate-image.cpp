class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(n));


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                ans[j][n-1-i]=matrix[i][j];
               
            }
        }
        matrix=ans;
    }
};