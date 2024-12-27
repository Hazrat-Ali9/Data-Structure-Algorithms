class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return nullptr;

        // Step 1: Create the backbone (vine)
        // Temporary dummy node
        TreeNode* vineHead = new TreeNode(0);
        vineHead->right = root;
        TreeNode* current = vineHead;
        while (current->right) {
            if (current->right->left) {
                rightRotate(current, current->right);
            } else {
                current = current->right;
            }
        }

        // Step 2: Count the nodes
        int nodeCount = 0;
        current = vineHead->right;
        while (current) {
            ++nodeCount;
            current = current->right;
        }

        // Step 3: Create a balanced BST
        int m = pow(2, floor(log2(nodeCount + 1))) - 1;
        makeRotations(vineHead, nodeCount - m);
        while (m > 1) {
            m /= 2;
            makeRotations(vineHead, m);
        }

        TreeNode* balancedRoot = vineHead->right;
        // Delete the temporary dummy node
        delete vineHead;
        return balancedRoot;
    }

private:
    // Function to perform a right rotation
    void rightRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        parent->right = tmp;
    }

    // Function to perform a left rotation
    void leftRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;
        parent->right = tmp;
    }

    // Function to perform a series of left rotations to balance the vine
    void makeRotations(TreeNode* vineHead, int count) {
        TreeNode* current = vineHead;
        for (int i = 0; i < count; ++i) {
            TreeNode* tmp = current->right;
            leftRotate(current, tmp);
            current = current->right;
        }
    }
};