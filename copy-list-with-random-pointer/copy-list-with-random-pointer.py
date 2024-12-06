/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node node = head;
        while(node!=null){
            Node temp = node.next;
            node.next = new Node(node.val);
            node.next.next = temp;
            node = temp;
        }
        node = head;
        while(node!=null){
            if(node.random!=null){
                node.next.random = node.random.next;
            }
            node = node.next.next;
        }
        Node ans = new Node(0);
        Node helper = ans;
        while(head!=null){
            helper.next = head.next;
            helper = helper.next;
            
            head.next = head.next.next;
            head = head.next;
        }
        return ans.next;
    }
}