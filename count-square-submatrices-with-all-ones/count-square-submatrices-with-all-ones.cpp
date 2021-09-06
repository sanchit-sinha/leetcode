const int N = 301;
int dp[N+2][N+2];
class Solution {
public:
    int getAr(int x1, int y1, int x2, int y2, int n, int m){
        int cnt = dp[x1][y1];
        if(y2 - 1 >= 0 && y2 - 1 < m) cnt -= dp[x1][y2 - 1];
        if(x2 - 1 >= 0 && x2 - 1 < n) cnt -= dp[x2 - 1][y1];
        if(x2 - 1 >= 0 && x2 - 1 < n && y2 - 1 >= 0 && y2 - 1 < m)
            cnt += dp[x2 - 1][y2 - 1];
        
        return cnt;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = (int)matrix.size(), m = (int)matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) dp[i][j] = matrix[i][j];
                else if(i == 0) dp[i][j] = dp[i][j - 1] + matrix[i][j];
                else if(j == 0) dp[i][j] = dp[i - 1][j] + matrix[i][j];
                else{
                    dp[i][j] = dp[i - 1][j];
                    for(int k = j; k >= 0; k--) dp[i][j] += matrix[i][k];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k <= min(i, j); k++){
                    int area = getAr(i,j, i - k, j - k, n, m);
                    if(area == (k + 1)*(k + 1)) ans++;
                }
            }
        }
        
        return ans;
    }
};