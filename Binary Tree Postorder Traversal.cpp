// recursive 2 min  1 AC
// iterative 20 min 4 RTE 1 AC
// Notice: 1. free(node) raise a runtime error when *node is allocate on stack!

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // destroy the tree finally
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        
        if(root==NULL) return res;
        
        st.push(root);
        while(!st.empty()) {
            if(st.top()==NULL) return res;
            
            TreeNode *node = st.top();
            st.pop();
            TreeNode *left = node->left;
            TreeNode *right = node->right;
            
            if (left==NULL && right==NULL) {
                res.push_back(node->val);
                // free(node);
            } else {
                node->left = NULL;
                node->right = NULL;
                
                st.push(node);
                if(right!=NULL) st.push(right);
                if(left!=NULL)  st.push(left);
            }
        }            
        return res;
    }
};

void printv(vector<int> v) {
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout<< *i <<" ";
    }cout<<endl;
}
int main(int argc, char const *argv[])
{
    Solution s;
    auto root = TreeNode(1);
    printv(s.postorderTraversal(&root));
    return 0;
}