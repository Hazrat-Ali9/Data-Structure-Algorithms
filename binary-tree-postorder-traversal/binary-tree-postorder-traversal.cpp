// C++ implementation
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        // If the root is null, return an empty list
        if (!root) {
            return result;
        }

        // Stack to manage the traversal
        stack<TreeNode*> mainStack;
        // Stack to manage the path
        stack<TreeNode*> pathStack;

        // Start with the root node
        mainStack.push(root);

        // Process nodes until the main stack is empty
        while (!mainStack.empty()) {
            root = mainStack.top();

            // If the node is in the path stack and it's the top, add its value
            if (!pathStack.empty() && pathStack.top() == root) {
                result.push_back(root->val);
                mainStack.pop();
                pathStack.pop();
            } else {
                // Push the current node to the path stack
                pathStack.push(root);
                // Push right child if it exists
                if (root->right) {
                    mainStack.push(root->right);
                }
                // Push left child if it exists
                if (root->left) {
                    mainStack.push(root->left);
                }
            }
        }

        return result;
    }
};