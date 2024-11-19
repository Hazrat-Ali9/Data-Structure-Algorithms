class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* curr = head, *prev = NULL, *nxt = NULL;
        int cnt = 0;
        while(curr != NULL && cnt < 2){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        head->next = swapPairs(nxt);
        return prev;
    }
};
