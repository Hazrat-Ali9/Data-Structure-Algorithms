class Solution {
    int[] dp;
    public int numDecodings(String s) {
        dp = new int[s.length()];
        Arrays.fill(dp, -1);
        return nWays(0, s);
    }
    int nWays(int i, String s){
        if(i >= s.length()) return 1;
        else if(s.charAt(i) == '0') return 0;
        else if(i == s.length()-1) return 1;
        else if(dp[i] != -1) return dp[i];
        else if(s.charAt(i) == '1' || (s.charAt(i) == '2' && (s.charAt(i + 1) >= '0' && s.charAt(i + 1) <= '6'))){
            return dp[i] = nWays(i + 1, s) + nWays(i + 2, s);
        }
        else return dp[i] = nWays(i + 1, s);
    }
}