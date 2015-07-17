// REDO
// 3min 4 RTE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root==NULL) return root;
    
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    

    root->left = right;
    root->right = left;
        
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
