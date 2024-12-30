class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        while(l < r){
            int m = (l + r + 1) / 2;
            if(getSum(index, m, n) <= maxSum) l = m;
            else r = m-1;
        }
        return l;
    }
    long getSum(int index, int value, int n){
        long cnt = 0;
        if (value > index){
            cnt += (long)(value + value - index) * (index + 1) / 2;
        }else{
            cnt += (long)(value + 1) * value / 2 + index - value + 1;
        }
        if(value >= n - index){
            cnt += (long)(value + value - n + 1 + index) * (n - index) / 2;
        }else{
            cnt += (long)(value + 1) * value / 2 + n - index - value;
        }   
        return cnt - value;
    }
};