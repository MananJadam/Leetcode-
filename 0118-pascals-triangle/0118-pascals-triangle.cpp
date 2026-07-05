class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        for(int row =1; row<=numRows; row++){
            vector<int> currentRow;
            long long value=1;
            currentRow.push_back(1);

            for(int col=1; col<row; col++){
            value= value*(row-col);
            value= value/(col);
            currentRow.push_back(value);
        }

        
        
        
        
        ans.push_back(currentRow);

        }
        return ans;
    }
    
};