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