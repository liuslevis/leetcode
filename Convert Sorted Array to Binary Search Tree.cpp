#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>
#include <locale>
using namespace std;

// 16:43 d1 ~ 15:04 d2
// 2 day AC, many runtime error, due to:
//
//   Notice: pointer (left, right) after init is NOT NULL!
//           need to set to NULL or cuz segmentfault
 struct TreeNode {
     int val;
     struct TreeNode *left; // need to set to NULL
     struct TreeNode *right;
 };

 struct TreeNode * newNode() {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    return node;
 }
 
void helper(struct TreeNode* root, int* nums, int numsSize) {
    if (numsSize <= 0) 
        return;
        
    if (numsSize >= 1) {
      cout <<"arr:";
        for (int i = 0; i < numsSize; ++i)
        {
          cout<<nums[i]<<" ";
        }cout<<endl;

         // Middle
        int mid = numsSize / 2;
        root->val = nums[mid];
        cout<<"mid:"<<mid<<"="<<nums[mid]<<endl;
        // left
        int leftSize = mid;
        if (leftSize > 0) {
            cout<<"leftSize:"<<leftSize<<endl;

            root->left = newNode();
            helper(root->left, nums, leftSize);
        }
        // Right
        int rightSize = numsSize - 1 - mid;
        if (rightSize > 0) {
            cout<<"rightSize:"<<rightSize<<endl;

            root->right = newNode();

            helper(root->right, nums + 1 + mid, rightSize);
        }
    }
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0) return NULL;

    struct TreeNode *root = newNode();

    if (numsSize >= 1) {
        helper(root, nums, numsSize);
    }
    return root;
}

void printTree(struct TreeNode* node) {
  // cout << "root->val:" << node->val << endl;
  // cout << "root->left->val:" << node->left->val << endl;
  // cout << "root->left->left->val:" << node->left->left->val << endl;
  // cout << "root->right->val:" << node->right->val << endl;
  // cout << "root->right->right:" << node->right->right << endl;
  // cout << "root->left->left->left:" << node->left->left->left << endl;
   if (node != NULL) {
     cout << "node val:" << node->val << endl;
     if (node->left != NULL) printTree(node->left);
     if (node->right != NULL) printTree(node->right);
   }
}

void test() {
  // int nums[] = {11,22,33,44, 55};
  int nums[] = {-1, 0, 1, 2};
  // sortedArrayToBST(nums, 5);
  printTree(sortedArrayToBST(nums, 4));
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}