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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        int mnDis = INT_MAX;
        ListNode *prevNode = head, *currNode = head->next;
        int currIndex = 1, prevCriticalIndex = 0, firstCriticalIndex = 0;
        while(currNode->next != NULL){
            if((currNode->val < prevNode->val && currNode->val < currNode->next->val) || (currNode->val > prevNode->val && currNode->val > currNode->next->val)){
                if(prevCriticalIndex == 0){
                    prevCriticalIndex = currIndex;
                    firstCriticalIndex = currIndex;
                }
                else{
                    mnDis = min(mnDis, currIndex-prevCriticalIndex);
                    prevCriticalIndex = currIndex;
                }
            }
            currIndex++;
            prevNode = currNode;
            currNode = currNode->next;
        }
        if(mnDis != INT_MAX){
            int mxDis = prevCriticalIndex - firstCriticalIndex;
            ans = {mnDis, mxDis};
        }
        return ans;
    }
};