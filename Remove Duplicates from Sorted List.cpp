// 4 CE 1 TLE 1AC
// notice: nil -> NULL in C

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (NULL == head) return head;
    if (NULL == head->next) return head;
    // len > 2
    struct ListNode *prev, *cur, *tmp;
    prev = head;
    cur = head->next;
    tmp = NULL;
    while(NULL != cur) {
        
        if(cur->val==prev->val) {
            tmp = cur;
            cur = cur->next;
            prev->next = cur;
            free(tmp);
            tmp = NULL;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}