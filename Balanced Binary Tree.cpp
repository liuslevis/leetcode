#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <locale>
using namespace std;

// 12:35 ~ 13:03 3WA 1AC , rescursive method
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
    struct Res {
        bool isBalance;
        int height;
        Res(bool b, int h) : isBalance(b), height(h) {}
    };
    Res tree_balance_height(TreeNode *root) {
        if (NULL==root) return Res(true, 0);
        
        Res left_res  = tree_balance_height(root->left);
        Res right_res = tree_balance_height(root->right);
        
        int left_height = 1+left_res.height;
        int right_height = 1+right_res.height;
        
        int diff = abs(left_height - right_height);
        int isBalance = diff > 1 ? false:true;
        int height = left_height > right_height? left_height:right_height;
        
        if (!left_res.isBalance || !right_res.isBalance)
            return Res(false, height);
        else
            return Res(isBalance, height);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if (NULL==root) return true;
        
        
        Res res = tree_balance_height(root);
        return res.isBalance;
    }
};