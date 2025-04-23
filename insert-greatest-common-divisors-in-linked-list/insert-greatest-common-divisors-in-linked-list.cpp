
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode *node1 = head, *node2 = head->next;
        while(node2 != NULL){
            int gcdVal = calGCD(node1->val, node2->val);
            ListNode *gcdNode = new ListNode(gcdVal);
            node1->next = gcdNode;
            gcdNode->next = node2;
            //Move forward
            node1 = node2;
            node2 = node2->next;
        }
        return head;
    }
    int calGCD(int a, int b){
        while(b){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};