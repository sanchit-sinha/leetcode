class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows, m = numRows;
        
        vector<vector<int>> ncr(n + 1, vector<int>(m + 1, 0));   
        ncr[0][0] = 1;
        /*
            ncr = (n) C (r-1) + (n-1)C(r-1)
        */
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(i == 0 && j == 0){
                    ncr[i][j] = 1;
                }
                else if(j == 0){
                    ncr[i][j] = 1; 
                }
                else{
                    ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
                }
            }
        }
        
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++){
            vector<int> v;
            for(int j = 0; j <= i; j++) v.push_back(ncr[i][j]);
            ans[i] = v;
        }
        
        return ans;
    }
};