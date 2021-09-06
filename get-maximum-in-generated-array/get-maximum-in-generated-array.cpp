class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n + 1, 0);
        nums[0] = 0;
        if(n == 0) return 0;
        
        nums[1] = 1;
        if(n == 1) return 1;
        
        for(int i = 1; i <= n; i++){
            if(i + i <= n) nums[2*i] = nums[i];
            if(2*i + 1 <= n) nums[2*i + 1] = nums[i] + nums[i + 1];
        }
        
        int ans = 0;
        for(auto x:nums) ans = max(ans, x);
        
        return ans;
    }
};