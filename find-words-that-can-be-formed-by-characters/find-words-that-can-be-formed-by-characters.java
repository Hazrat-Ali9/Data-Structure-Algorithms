class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] mp = new int[26];
        for(Character c : chars.toCharArray()) mp[c-'a']++;
        int ans = 0;
        for(String s : words){
            int[] cnt = new int[26];
            for(Character c : s.toCharArray()) cnt[c-'a']++;
            boolean isValid = true;
            for(Character c : s.toCharArray()){
                if(mp[c-'a'] < cnt[c-'a']){
                    isValid = false;
                    break;
                }
            }
            ans += isValid ? s.length() : 0;
        }
        return ans;
    }
}