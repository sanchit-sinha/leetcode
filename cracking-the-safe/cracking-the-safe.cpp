const int N = 5000;
vector<int> v[N];

vector<int> EulerPath;
int in[N], out[N];
void dfs_EulerPath(int node) {
	while (out[node]) {
		dfs_EulerPath(v[node][--out[node]]);
	}
	EulerPath.push_back(node);
}
bool findEulerianPath(int n) { /* 1: if its possible to find a eulerPath */
	// calculate the in and out degree for each node
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < (int)v[i].size(); j++)
			in[v[i][j]]++, out[i]++;

	// check if its possible to find euler path or not
	bool ok = 1;
	int numStartNode = 0, numEndNode = 0;
	for (int i = 1; i <= n; i++) {
		if (out[i] - in[i] > 1 || in[i] - out[i] > 1) ok = 0;
		else if (out[i] - in[i] == 1) numStartNode++;
		else if (in[i] - out[i] == 1) numEndNode++;
	}
    
	if (ok) 
        ok = ((numEndNode == 0 && numStartNode == 0) || (numEndNode == 1 && numStartNode == 1));
	if (!ok) return false;

	int node = 1;
	for (int i = 1; i <= n; i++)
		if (out[i] - in[i] == 1)
			node = i;

	dfs_EulerPath(node);
	return true;
}
class Solution {
public:
    vector<string> getNodes(int n, int k){
        vector<string> cur;
        if(n == 1){
            for(int j = 0; j < k; j++){
                char c = (char)(j + '0');
                string t;
                t.push_back(c), cur.push_back(t);
            }
            
            return cur;
        }
        vector<string> temp = getNodes(n - 1, k);
        
        int len = (int)temp.size();
        for(int j = 0; j < k; j++){
            for(int i = 0; i < len; i++){
                string t = temp[i] + (char)(j + '0');
                cur.push_back(t);
            }
        }
        
        return cur;
    }
    
    string crackSafe(int n, int k) {
        if(n == 1){
            string ans;
            for(int j = 0; j < k; j++){
                char c = (char)(j + '0');
                ans.push_back(c);
            }
            
            return ans;
        }
        
        vector<string> Nodes = getNodes(n - 1, k);
        int len = (int)Nodes.size();
        
        // clear
        for(int i = 0; i <= len; i++){
            v[i].clear();
            in[i] = out[i] = 0;
        }
        EulerPath.clear();
        
        map<string, int> id;
        for(int i = 0; i < len; i++) id[Nodes[i]] = i + 1;

        map<int, string> revid;
        for(int i = 0; i < len; i++) revid[i + 1] = Nodes[i];
        
        for(int i = 0; i < len; i++){
            string t = Nodes[i];
            int node = id[t];
            
            string s;
            for(int j = 1; j < (int)t.size(); j++) s.push_back(t[j]);
            for(int j = 0; j < k; j++){
                char c = (j + '0');
                s.push_back(c);
                
                int child = id[s];
                v[node].push_back(child);
                
                s.pop_back();
            }
        }
        
        bool got = findEulerianPath((int)id.size());
        assert(got == 1);
        
        EulerPath.pop_back();
        int lenn = (int)EulerPath.size();

        string ans;
        for(int i = 0; i < lenn; i++){
            string t = revid[EulerPath[i]];
            ans.push_back(t.back());
        }
        for(int i = 0; i < n - 1; i++) ans.push_back('0');
        
        return ans;
    }
};