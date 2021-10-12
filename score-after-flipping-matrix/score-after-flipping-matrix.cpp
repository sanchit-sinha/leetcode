class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = int(A.size()), m = (int)A[0].size();
        
        for(int i = 0; i < n; i++){
            if(A[i][0] == 0){
                // swap A[i]
                for(int j = 0; j < m; j++) A[i][j] = (A[i][j] ^ 1);
            }
        }
        
        for(int j = 0; j < m; j++){
            int cnt = 0;
            for(int i = 0; i < n; i++) cnt += A[i][j];
            
            int mx = max(cnt, n - cnt);
            if(mx != cnt){
                for(int i = 0; i < n; i++) A[i][j] = (A[i][j] ^ 1);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) ans += (A[i][j]) * (1 << (m - 1 - j));
        }
        
        return ans;
    }
};