class Solution {
    public int countOrders(int n) {
        int mod = 1000000007;
        long places = 2*n, cnt = 1;
        for(int i=n; i>=1; i--){
            cnt = (cnt*((places*(places-1))/2))%mod;
            places -= 2;
        }
        return (int)cnt;
    }
}