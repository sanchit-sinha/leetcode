class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        /*
            dp[i][0] : max profit till [0..i] selling the ith item
            dp[i][1] : max profit till [0..i] buying the ith item
        */
        
        dp[0][0] = -prices[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i - 1][0];
            if(dp[i - 1][1] != INT_MIN) dp[i][0] = max(dp[i][0], dp[i - 1][1] - prices[i]);
            
            dp[i][1] = dp[i - 1][1];
            if(dp[i - 1][0] != INT_MIN) dp[i][1] = max(dp[i][1], dp[i - 1][0] + prices[i]);
        }
        
        return dp[n - 1][1];
    }
};