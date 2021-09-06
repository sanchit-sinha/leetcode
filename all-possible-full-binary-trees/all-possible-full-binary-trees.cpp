/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int N = 21;
vector<TreeNode*> v[N + 3];

vector<TreeNode*> solve(int n){
    if((int)v[n].size() || n%2 == 0) return v[n];
    
    vector<TreeNode*> ans;
 
    if(n == 1){
        TreeNode* root = new TreeNode(0);
        root->left = NULL, root->right = NULL;
        
        ans.push_back(root);
        return v[1] = ans;
    } 

    for(int left = 1; left < n - 1; left += 2){
        int right = n - 1 - left;
        
        vector<TreeNode*> vl, vr;
        vl = solve(left);
        vr = solve(right);
        
        int lenLeft = (int)vl.size();
        int lenRight = (int)vr.size();
        
        // TreeNode* root = new TreeNode(0);
        for(int i = 0; i < lenLeft; i++){
            for(int j = 0; j < lenRight; j++){
                TreeNode* root = new TreeNode(0);
                root->left = vl[i];
                root->right = vr[j];
    
                ans.push_back(root);
            }
        }
    }
    
    return v[n] = ans;
}
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        for(int i = 0; i <= n; i++) v[i].clear();
        
        return solve(n);
    }
};