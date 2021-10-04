/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string &ans, int d = 0){
        if(root == NULL) {
            for(int i = 0; i < d; i++) ans.push_back('?');
            ans += to_string(1001);
            
            return;
        }
        for(int i = 0; i < d; i++) ans.push_back('?');
        ans += to_string(root->val);
        
        preorder(root->left, ans, d + 1);
        preorder(root->right, ans, d + 1);
    }
        
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        preorder(root, ans);
        // cout << ans << "\n";
        return ans;
    }
    
    int getVal(int &index, string &traversal){
        int n = (int)traversal.size();
        string ans;
        
        int l = index;
        int r = index;
        
        while(r < n && traversal[r] != '?') r++;
        r--;
        
        index = r;
        string t = traversal.substr(l, r - l + 1);
        return stoi(t);
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        int n = (int)traversal.size();
        unordered_map<int, TreeNode*> m;
        
        int i = 0;
        TreeNode* root = new TreeNode(getVal(i, traversal));
        m[0] = root;
        if(root -> val == 1001) return NULL;
        
        i++;
        int prev = 0;
        for(; i < n; i++){
            int curr = 0;
            while(i < n && traversal[i] == '?') curr++, ++i;
            int val = getVal(i, traversal);
            
            TreeNode* newnode;
            if(val == 1001) newnode = NULL;
            else newnode = new TreeNode(val);
            
            if(curr > prev){
                if(m[curr - 1] != NULL) m[curr - 1] -> left = newnode;
            }
            else{
                if(m[curr - 1] != NULL) m[curr - 1] -> right = newnode;
            }
            
            m[curr] = newnode;
            prev = curr;
        }
        return m[0];    
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = (int)data.size();
        if(n == 0) return NULL;
        return recoverFromPreorder(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));