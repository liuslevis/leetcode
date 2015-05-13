/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive: 3WA 1AC
class Solution {
private:
    vector<int> helper(TreeNode*root, vector<int> *v) {
        if (root==NULL) return *v;
        
        helper(root->left, v);
        v->push_back(root->val);
        helper(root->right, v);
        
        return *v;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<int> *v = &res;
        helper(root, v);
        return *v;
    }
};
// Iterative solution: 2CE 1AC destroy tree node value
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > res;
        if (root == NULL) return res;
        stack<TreeNode* > s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            
            if (cur!=NULL) {
                if (cur->left==NULL && cur->right==NULL) {
                    res.push_back(cur->val);
                } else {
                    s.push(cur->right);
                    s.push(cur);
                    s.push(cur->left);
                    cur->left = NULL;
                    cur->right = NULL;
                }                
            }
        }
        
        return res;
    }
};