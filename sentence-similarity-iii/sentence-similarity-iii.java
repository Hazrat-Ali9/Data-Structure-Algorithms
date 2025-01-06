class Solution {
    public boolean areSentencesSimilar(String s1, String s2) {
        String[] s1Words = s1.split(" "), s2Words = s2.split(" ");
        int l=0, r1=s1Words.length-1, r2=s2Words.length-1, n = s1Words.length, m = s2Words.length;
        if(n > m) return areSentencesSimilar(s2, s1);
        while(l < n && s1Words[l].equals(s2Words[l])) l++;
        while(r1 >= 0 && s1Words[r1].equals(s2Words[r2])){
            r1--;
            r2--;
        }
        return r1 < l;
    }
}