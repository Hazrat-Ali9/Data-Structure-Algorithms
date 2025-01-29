
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i=0, j=0, curr=0, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> mat(m, vector<int>(n, -1));
        while(head){
            mat[i][j] = head->val;
            int newI = i+dir[curr][0], newJ = j+dir[curr][1];
            if(min(newI, newJ)<0 || newI>=m || newJ>=n || mat[newI][newJ]!=-1) curr = (curr+1)%4;
            i += dir[curr][0];
            j += dir[curr][1];
            head = head->next;
        }
        return mat;
    }
};