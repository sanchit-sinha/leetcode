class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = (int)row.size();
        vector<int> p(n, 0), m(n, 0);
        for(int i = 0; i < n; i++) m[row[i]] = i;
        for(int i = 0; i < n; i += 2){
            p[i] = i + 1;
            p[i + 1] = i;
        }
        
        // for(int i = 0; i < n; i++) cout << i << " -> " << m[i] <<  "\n";
        
        int ans = 0;
        for(int i = 0; i < n; i += 2){
            int first = row[i];
            int second = row[i + 1];
            
            if(p[first] == second) continue;
            
            // first unchanged 
            int wants = p[first];
            int indexs = m[wants];
            int indexsp = indexs;
            if(indexsp&1) indexsp--;
            else indexsp++;
            if(row[indexsp] == p[second]){
                row[i + 1] = wants;
                row[indexs] = second;
                
                m[wants] = i + 1;
                m[second] = indexs;
                
                ans++;
                // cout << "in1 " << i << " " << ans << "\n\n";
                continue;
            }
            
            // second unchanged
            int wantf = p[second];
            int indexf = m[wantf];
            
            row[i] = wantf;
            row[indexf] = first;

            m[wantf] = i;
            m[first] = indexf;

            ans++;
            // cout << wantf << ": " << indexf << "\n";
            // cout << "in2 " << i  << " " << ans << "\n";
            // for(int k = 0; k < n; k++) cout << row[k] << " ";
            // cout << "\n\n";
        }
        return ans;
    }
};