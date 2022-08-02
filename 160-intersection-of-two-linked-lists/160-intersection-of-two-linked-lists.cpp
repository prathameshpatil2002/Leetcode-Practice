/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        int l1 = 0,l2 = 0;
        ListNode* t1 = headA,*t2 = headB;
        
        while(t1){
            l1++;
            t1 = t1->next;
        }
        while(t2){
            l2++;
            t2 = t2->next;
        }
        t1 = headA,t2 = headB;
        if(l1>l2){
            while(l1!=l2){
                t1 = t1->next;
                l1--;
            }
        }
        else if(l2>l1){
            while(l1!=l2){
                t2 = t2->next;
                l2--;
            }
        }
        while(t1&&t2){
            if(t1==t2){
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
};