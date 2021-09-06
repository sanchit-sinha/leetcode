class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex, m = rowIndex;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= i; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
        }
        
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(dp[n][i]);
        }
        
        return ans;
    }
};