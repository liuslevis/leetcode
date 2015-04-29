

/**
 * 15min AC, 3 submit
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        else 
        {
            int leftDepth  = 1 + maxDepth(root->left );
            int rightDepth = 1 + maxDepth(root->right);
            return leftDepth > rightDepth ? leftDepth : rightDepth;
        }
    }
};