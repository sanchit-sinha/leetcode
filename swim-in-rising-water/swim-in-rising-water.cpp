int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool dfs(int i, int j, vector<vector<int>>& grid,  vector<vector<bool>>& vis){
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    vis[i][j] = 1;
    
    if(i == n - 1 && j == m - 1) return 1;
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        
        if(x >= 0 && y >= 0 && x < n && y < m){
            if(!vis[x][y] && grid[x][y] != INT_MAX){                        
                if(dfs(x,y,grid, vis)) return 1;
           }
        }
    }
    
    return 0;
}
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                v.push_back({grid[i][j], {i,j}});
            }
        }
        
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        vector<vector<bool>>vis(n, vector<bool>(m, 0));
        int len = (int)v.size();
        for(int i = 0; i < len; i++){
            auto p = v[i];
            int x = p.second.first;
            int y = p.second.second;
            
            grid[x][y] = INT_MAX;
            for(int xx = 0; xx < n; xx++){
                for(int yy = 0; yy < m; yy++) vis[xx][yy] = 0;
            }

            if(grid[0][0] == INT_MAX || !dfs(0,0,grid, vis)){
                return v[i].first;
            }
        }
        
        return -1;
    }
};