class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sumPower = 0;
        for(int x : batteries) sumPower += x;
        long long l = 1, r = sumPower/n;
        while(l < r){
            long long target = (r + l + 1) / 2;
            long long extra = 0;
            for(int x : batteries) extra += min((long long)x, target);
            if(extra >= n*target) l = target;
            else r = target - 1;
        }
        return l;
    }
};