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
    int pairSum(ListNode* head) {
            stack<int> s;
            ListNode*slow = head,*fast = head;
        
            while(slow&&fast&&fast->next){
                s.push(slow->val);
                slow = slow->next;
                fast = fast->next->next;
            }
        
           int ans = INT_MIN;
        
            while(slow){
                ans = max(ans,s.top()+slow->val);
                s.pop();
                slow = slow->next;
            }
        return ans;
    }
};