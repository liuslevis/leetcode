//4 min 4
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        
        queue<TreeNode*> nextLevel;
        nextLevel.push(root);
        while (!nextLevel.empty()) {
            queue<TreeNode*> thisLevel = nextLevel;
            // nextLevel.clear();
            while(!nextLevel.empty()) nextLevel.pop();
            
            vector<int> levelVals;
            while(!thisLevel.empty()) {
                TreeNode *cur = thisLevel.front();
                if (cur->left!=NULL)  nextLevel.push(cur->left);
                if (cur->right!=NULL) nextLevel.push(cur->right);
                
                levelVals.push_back(cur->val);
                thisLevel.pop();
            }
            res.push_back(levelVals);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

