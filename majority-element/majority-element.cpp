class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=INT_MIN, num2=INT_MIN, cnt1=0, cnt2=0;
        for(int x : nums){
            if(x == num1) cnt1++;
            else if(x == num2) cnt2++;
            else if(cnt1 == 0){
                num1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                num2 = x;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int x : nums){
            if(num1 == x) cnt1++;
            if(num2 == x) cnt2++;
        }
        vector<int> ans;
        if(cnt1 > nums.size()/3) ans.push_back(num1);
        if(cnt2 > nums.size()/3) ans.push_back(num2);
        return ans;
    }
};