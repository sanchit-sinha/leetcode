int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int i, int j, int mid, vector<vector<int>>& grid,  vector<vector<bool>>& vis){
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    vis[i][j] = 1;
    
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        
        if(x >= 0 && y >= 0 && x < n && y < m){
            if(!vis[x][y] && grid[x][y] <= mid){                        
                dfs(x,y,mid,grid,vis);
           }
        }
    }
}
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        int l = 0, r = n*n, ans = 0;
        while(l <= r){
            int mid = (l + (r - l)/2);
            vector<vector<bool>> vis(n, vector<bool>(m, 0));
            
            if(grid[0][0] > mid){
                l = mid + 1;
            }
            else{
                dfs(0,0,mid,grid,vis);
                if(vis[n - 1][m - 1]){
                    ans = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
        }
        return ans;
    }
};