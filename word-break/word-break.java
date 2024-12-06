class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length()+1];
        dp[0] = true;
        for(int i=0; i<=s.length(); i++){
            for(String str : wordDict){
                if(dp[i] && i+str.length()<=s.length() && s.substring(i, i+str.length()).equals(str)){
                    dp[i+str.length()] = true;
                }
            }
        }
        return dp[s.length()];
    }
}