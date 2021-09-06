class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));   
        
        for(int j = 0; j <= m; j++) dp[0][j] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]){
                    if(dp[i - 1][j - 1]) dp[i][j] = 1;
                }
                if(dp[i][j - 1]) dp[i][j] = 1;
            }
        }
        
        return dp[n][m];
    }
};