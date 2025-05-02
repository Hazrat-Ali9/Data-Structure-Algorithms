class Solution {
    public int minLength(String s) {
        while(s.contains("AB") || s.contains("CD")){
            if(s.contains("AB")) s = s.replace("AB", "");
            else if(s.contains("CD")) s = s.replace("CD", "");
        }
        return s.length();
    }
}