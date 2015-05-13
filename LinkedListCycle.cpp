/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // space O(N), time O(N) solution: 1 AC
class Solution {
private:
    unordered_map<ListNode* ,bool> hash;     
public:
    bool hasCycle(ListNode *head) {
        ListNode *cur = head;
        while(cur != NULL) {
            if (hash.find(cur) == hash.end()) {
                hash[cur] = true;    
            } else {
                return true;
            }
            cur = cur->next;
        }
        
        // circle linked list could not reach the end
        return false;
    }
};


// AHA! In-space solution, ref: https://leetcode.com/discuss/13688/my-faster-and-slower-runner-solution
// use 2 nodes: faster and slower, which forward 2 and 1 step each time. 
//             if there's a circle, faster catches slower; else faster would reach the end.
// 1 AC
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *faster = head;
        ListNode *slower = head;
        
        while(slower!=NULL && faster!=NULL && faster->next!=NULL) {
            slower = slower->next;
            faster = faster->next->next;
            if (faster == slower) return true;
        }
        
        // circle linked list could not reach the end
        return false;
    }
};
