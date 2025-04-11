class Solution {
public:
    int mxHeightAfterRemoval[100001];
    int currMxHeight = 0;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root, 0);
        currMxHeight = 0;
        traverseRightToLeft(root, 0);
        int qCnt = queries.size();
        vector<int> qResult(qCnt);
        for(int i=0; i<qCnt; i++){
            qResult[i] = mxHeightAfterRemoval[queries[i]];
        }
        return qResult;
    }
    void traverseLeftToRight(TreeNode *node, int currHeight){
        if(node == NULL) return;
        // Store the maximum height if this node were removed
        mxHeightAfterRemoval[node->val]= currMxHeight;
        // Update the current maximum height
        currMxHeight = max(currMxHeight, currHeight);
        // Traverse left subtree first, then right
        traverseLeftToRight(node->left, currHeight+1);
        traverseLeftToRight(node->right, currHeight+1);
    }
    void traverseRightToLeft(TreeNode *node, int currHeight){
        if(node == NULL) return;
        // Update the maximum height if this node were removed
        mxHeightAfterRemoval[node->val] = max(mxHeightAfterRemoval[node->val], currMxHeight);
        // Update the current maximum height
        currMxHeight = max(currHeight, currMxHeight);
        // Traverse right subtree first, then left
        traverseRightToLeft(node->right, currHeight + 1);
        traverseRightToLeft(node->left, currHeight + 1);
    }
};