// Split linked list in parts
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *curr = head;
        while(curr){
            curr = curr->next;
            n++;
        }
        vector<ListNode*> ans;
        int width = n/k, remain = n%k;
        curr = head;
        for(int i=0; i<k; i++){
            ListNode *root = curr;
            for(int j=0; j<width+(i<remain ? 1 : 0)-1; j++){
                if(curr) curr = curr->next;
            }
            if(curr){
                ListNode *prev = curr;
                curr = curr->next;
                prev->next = NULL;
            }
            ans.push_back(root);
        }
        return ans;
    }
};