const int N = 1e5 + 11;
vector<int> v[N];
int dp[N], level[N], parent[N];
vector<vector<int>> ans;
class Solution {
public:
    void dfs(int node, int p){
        parent[node] = p;
        for(auto child: v[node]){
            if(level[child] == 0){
                level[child] = level[node] + 1;
                dfs(child, node);
                
                dp[node] += dp[child];
            }
            else if (level[child] < level[node]) dp[node]++;
            else if (level[child] > level[node]) dp[node]--;
        }
        
        dp[node]--;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // clear
        for(int i = 0; i <= n; i++){
            v[i].clear();
            dp[i] = level[i] = parent[i] = 0;
        } 
        ans.clear();
        
        for(auto &x: connections){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        
        level[0] = 1;
        dfs(0, -1);
        
        // for(int i = 0; i < n; i++){
        //     cout << i << ": " << parent[i] << " - " << level[i] << " " << dp[i] << "\n";
        // }
        // cout << "\n";
        for(int i = 0; i < n; i++){
            if(dp[i] == 0 && level[i] > 1){
                vector<int> t;
                t.push_back(i);
                t.push_back(parent[i]);
                
                ans.push_back(t);    
            }
        }
        
        return ans;
    }
};