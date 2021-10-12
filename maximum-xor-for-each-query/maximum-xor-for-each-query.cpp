class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = (int)nums.size();
        vector<int> pfx(n, 0);
        
        for(int i = 0; i < n; i++){
            (i == 0) ? pfx[i] = nums[i] : pfx[i] = (pfx[i - 1] ^ nums[i]); 
        }
        
        int mx = (1 << maximumBit) - 1;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int val = (mx ^ pfx[n - 1 - i]);
            ans.push_back(val);
        }
        
        return ans;
    }
};