/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        getparentbyBFS(parent,root);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        q.push(target);
        int lev=0;
        while(!q.empty()){
            int n=q.size();
            if(lev==k)
                break;
            lev++;
            while(n--){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left&&!vis[curr->left]){
                    vis[curr->left]=true;
                    q.push(curr->left);
                }
                 if(curr->right&&!vis[curr->right]){
                    vis[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent[curr]&&!vis[parent[curr]]){
                    vis[parent[curr]]=true; 
                    q.push(parent[curr]);
                }
            }
        }
        vector<int>ans;
        while(q.size()>0){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
    void getparentbyBFS(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left){
                    parent[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                      parent[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
    }
};