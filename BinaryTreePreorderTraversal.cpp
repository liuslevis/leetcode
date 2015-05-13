/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // Recursive solution: 3 WA -> 1 AC
 // Iterative solution: 2 WA -> 1 AC
class Solution {
private:

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node!=NULL) {
                res.push_back(node->val);
                s.push(node->right);
                s.push(node->left);
            }
        }
        return res;
    }
};