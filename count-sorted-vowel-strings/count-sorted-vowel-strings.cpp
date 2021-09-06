const int M = 5;
const int N = 51;
char use[] = {'a', 'e', 'i', 'o', 'u'};
int dp[N + 3][M];

class Solution {
public:
    int countVowelStrings(int n) {
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 5; j++){
                dp[i][j] = 0;
            }
        }
        
        for(int j = 0; j < 5; j++) dp[0][j] = 1;        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 5; j++){
                for(int k = 0; k <= j; k++){
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        
        
        int ans = 0;
        for(int i = 0; i < 5; i++){
            ans += dp[n - 1][i];
        }
        
        return ans;
    }
};