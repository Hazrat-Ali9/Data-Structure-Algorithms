class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size(), ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(pq.size()){
            auto x = pq.top(); pq.pop();
            ans = max(ans, x[0]);
            int i=x[1], j=x[2];
            if(heights[i][j]==-1) continue;
            if(i==n-1 && j==m-1) break;
            for(int k=0; k<4; k++){
                int row = i + dx[k];
                int col = j + dy[k];
                if(row<0 || row>=n || col<0 || col>=m || heights[row][col]==-1) continue;
                pq.push({abs(heights[i][j]-heights[row][col]), row, col});
            }
            heights[i][j] = -1;
        }
        return ans;
    }
};