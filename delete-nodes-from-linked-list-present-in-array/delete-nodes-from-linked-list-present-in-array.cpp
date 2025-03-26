
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());
        while(head != NULL && valuesToRemove.count(head->val) > 0){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        if(head == NULL) return NULL;
        ListNode *curr = head;
        while(curr->next != NULL){
            if(valuesToRemove.contains(curr->next->val)){
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};