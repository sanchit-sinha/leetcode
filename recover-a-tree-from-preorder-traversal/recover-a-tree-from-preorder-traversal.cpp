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
class Solution {
public:
    int getVal(int &index, string &traversal){
        int n = (int)traversal.size();
        string ans;
        
        int l = index;
        int r = index;
        
        while(r < n && traversal[r] != '-') r++;
        r--;
        
        index = r;
        return stoi(traversal.substr(l, r - l + 1));
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int n = (int)traversal.size();
        unordered_map<int, TreeNode*> m;
        
        int i = 0;
        TreeNode* root = new TreeNode(getVal(i, traversal));
        m[0] = root;
        
        i++;
        int prev = 0;
        for(; i < n; i++){
            int curr = 0;
            while(i < n && traversal[i] == '-') curr++, ++i;
            int val = getVal(i, traversal);
            
            TreeNode* newnode = new TreeNode(val);
            if(curr > prev){
                m[curr - 1] -> left = newnode;
            }
            else{
                m[curr - 1] -> right = newnode;
            }
            
            m[curr] = newnode;
            prev = curr;
        }
        return m[0];    
    }
};