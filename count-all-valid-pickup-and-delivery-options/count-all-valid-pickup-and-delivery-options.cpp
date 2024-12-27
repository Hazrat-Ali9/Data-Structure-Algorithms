class Solution {
public:
    int mod = 1e9+7;
    int countOrders(int n) {
        long places = 2*n, cnt = 1;
        for(int i=n; i>=1; i--){
            cnt = (cnt*((places*(places-1))/2))%mod;
            places -= 2;
        }
        return cnt;
    }
};