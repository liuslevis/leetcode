// 8 min, 1 CE 1 RTE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool hasChild(TreeNode *root, TreeNode* p) {
        if (root==NULL) return false;
        if (root==p) return true;
        return hasChild(root->left, p) || hasChild(root->right, p);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *last = root;
        TreeNode *cur = root;
        while (hasChild(cur, p) && hasChild(cur, q)) {
            if (hasChild(cur->left, p) && hasChild(cur->left, q)) {
                last = cur;
                cur = cur->left;
            }
            else if (hasChild(cur->right, p) && hasChild(cur->right, q)) {
                last = cur;
                cur = cur->right;
            } else {
                return cur;
            }
            
        }
        return root;
    }
};
