class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for(char c : s.toCharArray()) freq.put(c, freq.getOrDefault(c, 0)+1);
        int ans = 0;
        boolean hasOddFreq = false;
        for(int cnt : freq.values()){
            if(cnt%2==0) ans+=cnt;
            else{
                ans += cnt-1;
                hasOddFreq = true;
            }
        }
        if(hasOddFreq) ans++;
        return ans;
    }
}