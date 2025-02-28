/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Maps values to TreeNode pointers
        unordered_map<int, TreeNode*> nodeMap;
        // Stores values which are children in the descriptions
        unordered_set<int> children;

        // Iterate through descriptions to create nodes and set up tree
        // structure
        for (const auto& description : descriptions) {
            // Extract parent value, child value, and whether it is a
            // left child (1) or right child (0)
            int parentValue = description[0];
            int childValue = description[1];
            bool isLeft = description[2];

            // Create parent and child nodes if not already created
            if (nodeMap.count(parentValue) == 0) {
                nodeMap[parentValue] = new TreeNode(parentValue);
            }
            if (nodeMap.count(childValue) == 0) {
                nodeMap[childValue] = new TreeNode(childValue);
            }

            // Attach child node to parent's left or right branch
            if (isLeft) {
                nodeMap[parentValue]->left = nodeMap[childValue];
            } else {
                nodeMap[parentValue]->right = nodeMap[childValue];
            }

            // Mark child as a child in the set
            children.insert(childValue);
        }

        // Find and return the root node
        for (auto& entry : nodeMap) {
            auto& value = entry.first;
            auto& node = entry.second;
            // Root node found
            if (children.find(value) == children.end()) {
                return node;
            }
        }

        // Should not occur according to problem statement
        return nullptr;
    }
};