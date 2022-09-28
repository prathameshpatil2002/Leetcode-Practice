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
    int len(ListNode* head){
        ListNode* tr = head;
        int l = 0;
        while(tr){
            l++;
            tr = tr->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(!head){
                return NULL;
            }
        int l = len(head);
        if(n > l){
            return NULL;
        }
        int c = 2;
        ListNode*tr = head;
        if(l==n){
            head =  head->next;
            return head;
        }
        if(n==1){
            while(tr->next->next){
                tr = tr->next;
            }
            tr->next = NULL;
            return head;
        }
        ListNode*ret  = NULL;
        n = l-n;
        while(c!=n+1){
            c++;
            tr = tr->next;
        }
        tr->next = tr->next->next;
        return head;
    }
};