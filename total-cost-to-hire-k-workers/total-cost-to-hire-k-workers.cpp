class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i = 0, j = costs.size()-1;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        while(k--){
            while(pq1.size() < candidates && i <= j) pq1.push(costs[i++]);
            while(pq2.size() < candidates && i <= j) pq2.push(costs[j--]);
            int x1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int x2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
            if(x1 <= x2){
                ans += x1;
                pq1.pop();
            }
            else{
                ans += x2;
                pq2.pop();
            }
        }
        return ans;
    }
};