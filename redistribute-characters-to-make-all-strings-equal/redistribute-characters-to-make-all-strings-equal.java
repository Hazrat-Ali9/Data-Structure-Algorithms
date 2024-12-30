class Solution {
    public boolean makeEqual(String[] words) {
        int[] cnt = new int[26];
        for(String word : words){
            for(Character c : word.toCharArray()) cnt[c-'a']++;
        }
        int n = words.length;
        for(int val : cnt){
            if(val % n != 0) return false;
        }
        return true;
    }
}