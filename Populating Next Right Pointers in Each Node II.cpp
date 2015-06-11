// recursive 8 min  WA
// iterative 13 min 2 WA 1 AC
// Notice: 1. Pass Test case yourself first!

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <stack>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root==NULL) {
            return;
        }
        
        deque<TreeLinkNode *> q;
        q.push_back(root);
        while(!q.empty()) {
            // for each layer
            deque<TreeLinkNode *> nextLayer;
            TreeLinkNode *node;
            while(!q.empty()) {
                node = q.front();
                q.pop_front();
                node->next = q.empty() ? NULL : q.front();
                
                if (NULL!=node->left)  nextLayer.push_back(node->left );
                if (NULL!=node->right) nextLayer.push_back(node->right);
            }
            // q.empty()
            q = nextLayer;

        }
    }
};