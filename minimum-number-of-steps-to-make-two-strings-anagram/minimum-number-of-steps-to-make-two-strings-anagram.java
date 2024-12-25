class Solution {
    public int minSteps(String s, String t) {
        int[] cnt = new int[26];
        for(int i=0; i<s.length(); i++){
            cnt[s.charAt(i)-'a']++;
            cnt[t.charAt(i)-'a']--;
        }
        int ans = 0;
        for(int i=0; i<26; i++) ans += Math.max(0, cnt[i]);
        return ans;
    }
}