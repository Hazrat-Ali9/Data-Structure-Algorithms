class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        // If the root is null, return the empty list
        if (root == nullptr) return result;
        stack<Node*> nodeStack;
        nodeStack.push(root);
        // Traverse the tree using the stack
        while (!nodeStack.empty()) {
            Node* currentNode = nodeStack.top();
            nodeStack.pop();
            result.push_back(currentNode->val);
            // Push all the children of the current node to the stack
            for (Node* child : currentNode->children) nodeStack.push(child);
        }
        // Reverse the result list to get the correct postorder traversal
        reverse(result.begin(), result.end());
        return result;
    }
};