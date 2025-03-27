class Solution {
    public String compressedString(String word) {
        StringBuilder comp = new StringBuilder();
        int i=0;
        while(i < word.length()){
            int cnt = 0;
            char currChar = word.charAt(i);
            while(i < word.length() && cnt < 9 && word.charAt(i)==currChar){
                i++;
                cnt++;
            }
            comp.append(cnt).append(currChar);
        }
        return comp.toString();
    }
}