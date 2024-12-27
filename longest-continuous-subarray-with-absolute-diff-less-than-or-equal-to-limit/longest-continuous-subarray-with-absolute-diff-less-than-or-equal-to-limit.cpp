class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), i=0, j=0, mxLen = 0;
        multiset<int> s;
        while(j < n){
            s.insert(nums[j]);
            int diff = *s.rbegin()-*s.begin();
            while(i<j && diff>limit){
                auto x = s.find(nums[i]);
                s.erase(x);
                diff = *s.rbegin()-*s.begin();
                i++;
            }
            mxLen = max(mxLen, (int)s.size());
            j++;
        }
        return mxLen;
    }
};