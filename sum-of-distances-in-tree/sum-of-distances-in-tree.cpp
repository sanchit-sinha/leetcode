class Solution {
public:
    int dfs(int node, int pr, vector<vector<int>> &v, vector<int> &subtree, int &ans, int d = 0){
        int n = (int)subtree.size();
        ans += d;
        
        int nodes = 1;
        for(auto &child: v[node]){
            if(child != pr){
                int childs = dfs(child, node, v, subtree, ans, d + 1);
                nodes += childs;
            }
        }
        return subtree[node] = nodes;
    }
    void dfs2(int node, int pr, vector<vector<int>> &v, vector<int> &ans, vector<int> &subtree){
        int n = (int)ans.size();
        for(auto &child: v[node]){
            if(child != pr){
                ans[child] = ans[node] + (n - subtree[child]) - subtree[child];
                dfs2(child, node, v, ans, subtree);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for(auto &x: edges){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        
        vector<int> ans(n ,0), subtree(n, 0);
        int x = dfs(0, 0, v, subtree, ans[0]);
        dfs2(0, 0, v, ans, subtree);
        
        return ans;
    }
};