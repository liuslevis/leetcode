// recursive 14 min  3 WA 1 AC
// iterative  6 min  1 WA 1 AC
// Notice: 1. Missconsider Symmetric Tree Define  2. check TC by hand!
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // Recusively
class Solution {
public:
    bool isSymmHelper(TreeNode* n, TreeNode* m) {
        if (NULL==n && NULL==m) return true;
        if ((NULL==n && NULL!=m) || (NULL==m && NULL!=n) || (m->val!=n->val))
            return false;
        return isSymmHelper(n->left, m->right) && isSymmHelper(n->right, m->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (NULL==root) return true;
        else 
            return isSymmHelper(root->left, root->right);
    }
};

// Iteratively
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
public:
    bool isSymmetric(TreeNode* root) {
        if (NULL==root) return true;
        deque<TreeNode*> lstack, rstack;
        if(NULL!=root->left)  lstack.push_back(root->left);
        if(NULL!=root->right) rstack.push_back(root->right);
        while(!lstack.empty() && !rstack.empty()) {
            TreeNode *lnode = lstack.front();
            TreeNode *rnode = rstack.front();
            lstack.pop_front();
            rstack.pop_front();
            
            if (lnode->val!=rnode->val) return false;
            
            if ((lnode->left != NULL  && rnode->right == NULL) ||
                (lnode->right != NULL && rnode->left == NULL))
                return false;
                
            if (lnode->left != NULL && rnode->right != NULL) {
                if (lnode->left->val != rnode->right->val) 
                    return false;
            }
            
            if (lnode->right!=NULL && rnode->left!=NULL) {
                if (lnode->right->val != rnode->left->val) 
                    return false;              
            }
            
            
            if (lnode->left!=NULL)  lstack.push_back(lnode->left);
            if (lnode->right!=NULL) lstack.push_back(lnode->right);

            if (rnode->right!=NULL) rstack.push_back(rnode->right);
            if (rnode->left!=NULL)  rstack.push_back(rnode->left);

        }

        if (lstack.size() == 0 && lstack.size()==rstack.size())
            return true;
        else
            return false;
    }
};
