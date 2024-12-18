class Solution {
public:
    int findNumberOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> length(n, 1), cnt(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(length[j]+1 > length[i]){
                        length[i] = length[j] + 1;
                        cnt[i] = 0;
                    }
                    if(length[j]+1 == length[i]) cnt[i] += cnt[j];
                }
            }
        }
        int mxLen = *max_element(length.begin(), length.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            if(length[i] == mxLen) ans += cnt[i];
        }
        return ans;
    }
};