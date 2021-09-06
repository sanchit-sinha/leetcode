class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int mx = 0, ans = 0;
        
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1) mx = prices[i];
            else{
                int val = mx - prices[i];
                ans = max(ans, val);
                mx = max(mx, prices[i]);
            }
        }
        
        return ans;
    }
};