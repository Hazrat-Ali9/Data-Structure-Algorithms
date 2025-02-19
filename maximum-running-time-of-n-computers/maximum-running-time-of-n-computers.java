class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long sumPower = 0;
        for(int x : batteries) sumPower += x;
        long l = 1, r = sumPower/n;
        while(l < r){
            long target = r - (r - l) / 2;
            long extra = 0;
            for(int x : batteries) extra += Math.min(x, target);
            if(extra >= (long)(n*target)) l = target;
            else r = target - 1;
        }
        return l;
    }
}