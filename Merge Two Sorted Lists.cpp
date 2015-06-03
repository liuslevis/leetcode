#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <locale>
using namespace std;

// 1 RTE 1 AC
// Notice: set next to NULL!

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode *newNode(int x) {
    ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = x;
    newNode->next = NULL; // Notice
    return newNode;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *p1, *p2, *cur, *tmp;
        
        p1 = l1;
        p2 = l2;
        head = newNode(0);
        cur = head;
        
        while(NULL!=p1 && NULL!=p2) {
            if (p1->val < p2->val) {
                cur->next = newNode(p1->val);
                cur = cur->next;
                p1 = p1->next;
            } else {
                cur->next = newNode(p2->val);
                cur = cur->next;
                p2 = p2->next;
            }
        }
        
        while(NULL!=p1) {
            cur->next = newNode(p1->val);
            cur = cur->next;
            p1 = p1->next;
        }
        
        while(NULL!=p2) {
            cur->next = newNode(p2->val);
            cur = cur->next;
            p2 = p2->next;
        }
        
        
        tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
};

void test() {
    // struct ListNode node(2);
    struct ListNode node = ListNode(2);
    cout<< node.val << node.next <<endl;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}