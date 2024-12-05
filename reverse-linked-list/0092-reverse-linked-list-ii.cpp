// reverse linked list
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for(int i=0; i<left-1; i++) prev = prev->next;
        ListNode *curr = prev->next;
        for(int i=0; i<right-left; i++){
            ListNode *forward = curr->next;
            curr->next = forward->next;
            forward->next = prev->next;
            prev->next = forward;
        }
        return dummy->next;
    }
};
