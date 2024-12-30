class Solution {
    public int minDeletions(String s) {
        int[] freq = new int[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        Arrays.sort(freq);
        int ans = 0;
        for(int i=24; i>=0; i--){
            if(freq[i] >= freq[i+1]){
                int tmp = freq[i];
                freq[i] = Math.max(0, freq[i+1]-1);
                ans += (tmp-freq[i]);
            }
        }
        return ans;
    }
}