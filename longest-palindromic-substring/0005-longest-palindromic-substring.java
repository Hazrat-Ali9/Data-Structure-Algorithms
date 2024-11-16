class Solution {
    public String longestPalindrome(String s) {
        for(int l=s.length(); l>0; l--){
            for(int i=0; i<=s.length()-l; i++){
                if(check(i, i+l, s)) return s.substring(i, i+l);
            }
        }
        return "";
    }
    boolean check(int i, int j, String s){
        int l = i, r = j-1;
        while(l < r){
            if(s.charAt(l) != s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }
}