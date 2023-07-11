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
    ListNode* deleteMiddle(ListNode* head) {
     ListNode*f = head,*s = head;
        while(s&&f&&f->next){
            s = s->next;
            f = f->next->next;
        }
        if(s==head){
            return NULL;
        }
        if(s->next==NULL){
            head->next = NULL;
            return head;
        }
        
            ListNode*t = s->next;
            s->val = s->next->val;
            s->next = t->next;
            delete t;
        
        
        return head;
    }
};