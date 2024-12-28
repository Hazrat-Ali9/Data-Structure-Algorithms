class Solution {
    public int countHomogenous(String s) {
        int ans = 0, cnt = 0, mod = 1000000007;
        for(int i=0; i<s.length(); i++){
            if(i==0 || s.charAt(i)==s.charAt(i-1)) cnt++;
            else cnt = 1;
            ans = (ans+cnt)%mod;
        }
        return ans;
    }
}