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
    ListNode* removeElements(ListNode* head, int val) {
         if(head==NULL){
            return NULL;
        }
        ListNode* front = head;
        ListNode* back = NULL;
        while(front != NULL){
            if(front->val == val){
                if(back == NULL){
                    head = head->next;
                    front = head;
                }
                else{
                    back->next = front->next;
                    front = back->next;
                }
            }
            else{
                back = front;
                front = front->next;
            }
        }
        return head;
    }
};