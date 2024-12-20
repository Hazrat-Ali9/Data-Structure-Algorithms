class Solution {
    public List<String> commonChars(String[] words) {
        int n = words.length;
        int[] commonCharCnt = new int[26];
        int[] currentCharCnt = new int[26];
        for(char c : words[0].toCharArray()) commonCharCnt[c-'a']++;
        for(int i=1; i<n; i++){
            Arrays.fill(currentCharCnt, 0);
            for(char c : words[i].toCharArray()) currentCharCnt[c-'a']++;
            for(int j=0; j<26; j++){
                commonCharCnt[j] = Math.min(commonCharCnt[j], currentCharCnt[j]);
            }
        }
        List<String> ans = new ArrayList<>();
        for(int i=0; i<26; i++){
            for(int j=0; j<commonCharCnt[i]; j++) ans.add(String.valueOf((char)(i+'a')));
        }
        return ans;
    }
}