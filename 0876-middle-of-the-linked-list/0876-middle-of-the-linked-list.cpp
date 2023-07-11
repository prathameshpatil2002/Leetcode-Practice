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
    ListNode* middleNode(ListNode* head) {
        if(!head ||!head->next){
            return head;
        }
        ListNode*s = head;
        ListNode*f= head->next;
        while(f&&f->next){
            s = s->next;
            f = f->next->next;
        }
        if (f){
            return s->next;
        }
        return s;
    }
};