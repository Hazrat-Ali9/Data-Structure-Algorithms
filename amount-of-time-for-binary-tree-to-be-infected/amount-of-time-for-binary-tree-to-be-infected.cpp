
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> mp;
        convertToGraph(root, 0, mp);
        queue<int> q;
        q.push(start);
        int min = 0;
        unordered_set<int> vis;
        vis.insert(start);
        while(!q.empty()){
            int sz = q.size();
            while(sz > 0){
                int curr = q.front(); q.pop();
                for(int x : mp[curr]){
                    if(vis.find(x) == vis.end()){
                        vis.insert(x);
                        q.push(x);
                    }
                }
                sz--;
            }
            min++;
        }
        return min-1;
    }
    void convertToGraph(TreeNode* curr, int parent, unordered_map<int, unordered_set<int>> &mp){
        if(curr == NULL) return;
        if(mp.find(curr->val) == mp.end()) mp[curr->val] = unordered_set<int>();
        unordered_set<int> &adjList = mp[curr->val];
        if(parent != 0) adjList.insert(parent);
        if(curr->left != NULL) adjList.insert(curr->left->val);
        if(curr->right != NULL) adjList.insert(curr->right->val);
        convertToGraph(curr->left, curr->val, mp);
        convertToGraph(curr->right, curr->val, mp);
    }
};