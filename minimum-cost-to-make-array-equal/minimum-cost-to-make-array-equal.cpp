class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = getCost(nums, cost, nums[0]);
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = (left + right) / 2;
            long long cost1 = getCost(nums, cost, mid);
            long long cost2 = getCost(nums, cost, mid + 1);
            ans = min(cost1, cost2);
            if (cost1 > cost2)
                left = mid + 1;
            else
                right = mid;
        }
        return ans;
    }
    long long getCost(vector<int>& nums, vector<int>& cost, int base) {
        long long result = 0;
        for (int i = 0; i < nums.size(); ++i)
            result += 1L * abs(nums[i] - base) * cost[i];
        return result;
    }
};