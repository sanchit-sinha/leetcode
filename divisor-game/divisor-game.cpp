class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n + 1, 0);
        if(n == 0) return 0;
        
        dp[1] = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                if(i%j == 0){
                    int div1 = j, div2 = i/j;
                    if(div1 > 0 && div1 < i && dp[i - div1] == 0) dp[i] = 1;
                    if(div2 > 0 && div2 < i && dp[i - div2] == 0) dp[i] = 1;
                }
            }
        }
        
        return dp[n];
    }
};