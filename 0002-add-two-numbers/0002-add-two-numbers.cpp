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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(!l1 || !l2){
          return NULL;
      }
        ListNode*ret = NULL,*retT = NULL;
        int carry = 0;
        while(l1&&l2){
            long long s = carry + l1->val + l2->val;
            if(s>=10){
                
                ListNode* n = new ListNode(s%10);
                s = s/10;
                carry = s;
                if(ret==NULL){
                    ret = n;
                    retT = n;
                }
                else{
                    retT->next = n;
                    retT = retT->next;
                }
            }
            else{
                carry = 0;
                ListNode* n = new ListNode(s%10);
                if(ret==NULL){
                    ret = n;
                    retT = n;
                }
                else{
                    retT->next = n;
                    retT = retT->next;
                }
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            while(l1){
                long long s = carry + l1->val;
            if(s>=10){
                ListNode* n = new ListNode(s%10);
                s = s/10;
                carry = s;
                if(ret==NULL){
                    ret = n;
                    retT = n;
                }
                else{
                    retT->next = n;
                    retT = retT->next;
                }
            }
            else{
                carry = 0;
                ListNode* n = new ListNode(s%10);
                if(ret==NULL){
                    ret = n;
                    retT = n;
                }
                else{
                    retT->next = n;
                    retT = retT->next;
                }
            }
            l1 = l1->next;
            }
        }
        else if(l2){
            while(l2){
                long long s = carry + l2->val;
            if(s>=10){
                ListNode* n = new ListNode(s%10);
                s = s/10;
                carry = s;
                if(ret==NULL){
                    ret = n;
                    retT = n;
                }
                else{
                    retT->next = n;
                    retT = retT->next;
                }
            }
            else{
                carry = 0;
                ListNode* n = new ListNode(s%10);
                if(ret==NULL){
                    ret = n;
                    retT = n;
                }
                else{
                    retT->next = n;
                    retT = retT->next;
                }
            }
            l2 = l2->next;
            }
        }
        if(carry!=0){
            ListNode* n = new ListNode(carry);
                if(ret==NULL){
                    ret = n;
                    retT = n;
                }
                else{
                    retT->next = n;
                    retT = retT->next;
                }
        }
        return ret;
    }
};