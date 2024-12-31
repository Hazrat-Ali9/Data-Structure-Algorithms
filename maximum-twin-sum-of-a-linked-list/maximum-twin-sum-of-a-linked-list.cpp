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
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *nxt, *prev = NULL;
        while(slow != NULL){
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }
        int ans = 0;
        ListNode *start = head;
        while(prev != NULL){
            ans = max(ans, prev->val+start->val);
            prev = prev->next;
            start = start->next;
        }
        return ans;
    }
};