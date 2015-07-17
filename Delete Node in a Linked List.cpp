// 1min 1AC
/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        
        // replace node val with next, one by one till the end.
        while(node->next != NULL) {
            node->val = node->next->val;    
            prev = node;
            node = node->next;
        }
        
        // del the last node
        prev->next = NULL;
        free(node);
    }
}

