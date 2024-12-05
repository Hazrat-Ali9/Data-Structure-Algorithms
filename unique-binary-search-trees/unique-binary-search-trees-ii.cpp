
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return allPossibleBST(1, n, memo);
    }
    vector<TreeNode*> allPossibleBST(int start, int end, map<pair<int, int>, vector<TreeNode*>>&memo){
        vector<TreeNode*> ans;
        if(start > end){
            ans.push_back(nullptr);
            return ans;
        }
        if(memo.find(make_pair(start, end)) != memo.end()){
            return memo[make_pair(start, end)];
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> leftSubTree = allPossibleBST(start, i-1, memo);
            vector<TreeNode*> rightSubTree = allPossibleBST(i+1, end, memo);
            for(auto left : leftSubTree){
                for(auto right : rightSubTree){
                    TreeNode* root = new TreeNode(i, left, right);
                    ans.push_back(root);
                }
            }
        }
        return memo[make_pair(start, end)] = ans;
    }
};