class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        int n = nums.size();
        vector<int> avg(n, -1);
        if(2*k+1 > n) return avg;
        vector<long long> prefSum(n+1);
        for(int i=0; i<n; i++) prefSum[i+1] = prefSum[i] + nums[i];
        for(int i=k; i<(n-k); i++){
            long long sum = prefSum[i+k+1] - prefSum[i-k];
            int average = sum / (2*k+1);
            avg[i] = average;
        }
        return avg;
    }
};