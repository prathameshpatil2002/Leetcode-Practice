/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return head;
        }
       ListNode*p = NULL;
       ListNode*curr = head;
       ListNode*tmp = NULL;
        while(curr&&curr->next){
            tmp = curr->next->next;
            if(p == NULL){
                p = curr;
                head = curr->next;
                curr->next->next = curr;
                curr->next = tmp;
                curr = tmp;
            }
            else{
                ListNode*t = p->next;
                p->next = curr->next;
                curr->next->next = curr;
                curr->next = tmp;
                curr = tmp;
                p = t;
            }
        }
        return head;
    }
};