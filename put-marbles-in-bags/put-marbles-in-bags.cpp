class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairWeight(n-1, 0);
        for(int i=0; i<n-1; i++){
            pairWeight[i] += weights[i] + weights[i+1];
        }
        sort(pairWeight.begin(), pairWeight.end());
        long long ans = 0;
        for(int i=0; i<k-1; i++){
            ans += pairWeight[n-2-i] - pairWeight[i];
        }
        return ans;
    }
};