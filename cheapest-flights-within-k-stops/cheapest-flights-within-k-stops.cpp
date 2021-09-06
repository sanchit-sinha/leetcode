class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<flight.size();i++){
            int s=flight[i][0];
            int d=flight[i][1];
            int p=flight[i][2];
            graph[s].push_back({d,p});
        }
        
        vector<vector<long long>>dist(k+2,vector<long long>(n,INT_MAX));
        dist[0][src]=0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]<INT_MAX){
                    for(auto f:graph[j]){
                        if(dist[i][j]+f.second<dist[i+1][f.first]){
                            dist[i+1][f.first]=dist[i][j]+f.second;
                        }
                    }
                }
            }
        }
        long long ans=INT_MAX;
        for(int i=0;i<=k+1;i++)ans=min(ans,dist[i][dst]);
        if(ans!=INT_MAX)return ans;
        return -1;
    }
};