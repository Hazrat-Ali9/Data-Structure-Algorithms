class Solution {
public:
    int dis(vector<int> &a, vector<int>&b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size();
        vector<int> vis(n, 0), minCost(n, INT_MAX);
        minCost[0] = 0;
        int curr = 0, ans = 0;
        while(curr >= 0){
            vis[curr] = 1;
            int currMin = INT_MAX, nxtPoint=-1;
            for(int i=0; i<n; i++){
                if(curr==i || vis[i]) continue;
                minCost[i] = min(dis(ps[curr], ps[i]), minCost[i]);
                if(currMin > minCost[i]){
                    currMin = minCost[i];
                    nxtPoint = i;
                }
            }
            ans += (currMin==INT_MAX ? 0 : currMin);
            curr = nxtPoint;
        }
        return ans;
    }
};