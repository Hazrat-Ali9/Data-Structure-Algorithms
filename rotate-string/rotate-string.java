class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length() != goal.length()) return false;
        String doubleStr = s + s;
        return doubleStr.contains(goal);
    }
}