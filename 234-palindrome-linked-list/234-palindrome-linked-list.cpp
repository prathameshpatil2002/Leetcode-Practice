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
    ListNode* reverse(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode*curr = head->next;
        ListNode*pre = head;
        ListNode*tmp = NULL;
        head->next = NULL;
        while(curr != NULL){
            tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
      //   if(head==NULL || head->next ==NULL){
      //       return true;
      //   }
        int l = 0;
        ListNode*n = head;
        while(n){
            l++;
            n =n->next;
        }
      //   if(l%2==0){
      //       int c = 1;
      //       ListNode*t = head;
      //       while(c<(l/2)){
      //           c++;
      //           t = t->next;
      //       }
      //       ListNode*l2 = t->next;
      //       t->next = NULL;
      //       ListNode*l1 = head;
      //       l2 = reverse(l2);
      //       int flag = 0;
      //       while(l1&&l2){
      //           if(l1->val!=l2->val){
      //               flag =1;
      //               break;
      //           }
      //           l1 = l1->next;
      //           l2 = l2->next;
      //       }
      //       if(flag){
      //           return false;
      //       }
      //       else{
      //           return true;
      //       }
      //   }
      //   else if(l%2!=0){
      //       int c = 1;
      //       ListNode*t = head;
      //       while(c<(l/2)){
      //           c++;
      //           t = t->next;
      //       }
      //       ListNode*l2 = t->next->next;
      //       t->next = NULL;
      //       ListNode*l1 = head;
      //       l2 = reverse(l2);
      //       int flag = 0;
      //       while(l1&&l2){
      //           if(l1->val!=l2->val){
      //               flag =1;
      //               break;
      //           }
      //           l1 = l1->next;
      //           l2 = l2->next;
      //       }
      //       if(flag){
      //           return false;
      //       }
      //       else{
      //           return true;
      //       }
      //   }
      // return false;  
        
      /* without reversing */
        
     stack<int> s;
     ListNode*slow = head,*fast = head;
        
    while(slow&&fast&&fast->next){
        s.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
        //s.pop();
        if(l%2){
            slow = slow->next;
        }
         int flag = 0;
        
        while(slow){
            if(s.top()==slow->val){
                s.pop();
                slow = slow->next;
                continue;
            }
            else{
                flag = 1;
                break;
            }
            
        }
        if(!flag){
            return true;
        }
        return false;
    }
};