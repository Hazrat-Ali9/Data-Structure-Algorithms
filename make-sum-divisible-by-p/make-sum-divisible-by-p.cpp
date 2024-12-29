class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), totalSum = 0;
        // Step 1: Calculate total sum and target remainder
        for(int num : nums) totalSum = (totalSum + num) % p;
        int target = totalSum % p;
        if(target == 0) return 0;  // The array is already divisible by p
        // Step 2: Use a hash map to track prefix sum mod p
        unordered_map<int, int> mp;
        mp[0] = -1;  // To handle the case where the whole prefix is the answer
        int currSum = 0, mnLen = n;
        // Step 3: Iterate over the array
        for(int i=0; i<n; i++){
            currSum = (currSum + nums[i]) % p;
            // Calculate what we need to remove
            int need = (currSum - target + p) % p;
            // If we have seen the needed remainder, we can consider this subarray
            if(mp.find(need) != mp.end()) mnLen = min(mnLen, i-mp[need]);
            // Store the current remainder and index
            mp[currSum] = i;
        }
        // Step 4: Return result
        return mnLen == n ? -1 : mnLen;
    }
};