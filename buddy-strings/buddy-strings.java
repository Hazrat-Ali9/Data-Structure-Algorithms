class Solution {
    public boolean buddyStrings(String s, String goal) {
        if(s.length() != goal.length()) return false;
        if(s.equals(goal)){
            // If we have 2 same characters in string 's',
            // we can swap them and still the strings will remain equal.
            int[] frequency = new int[26];
            for (char ch : s.toCharArray()) {
                frequency[ch - 'a'] += 1;
                if (frequency[ch - 'a'] == 2) {
                    return true;
                }
            }
            // Otherwise, if we swap any two characters, it will make the strings unequal.
            return false;
        }
        int fIndex = -1;
        int sIndex = -1;
        for(int i = 0; i<s.length(); ++i){
            if(s.charAt(i) != goal.charAt(i)){
                if(fIndex == -1) fIndex = i;
                else if(sIndex == -1) sIndex = i;
                else{
                    // We have at least 3 indices with different characters,
                    // thus, we can never make the strings equal with only one swap.
                    return false;
                }
            }
        }
        if(sIndex == -1){
            // We can't swap if the character at only one index is different.
            return false;
        }
        // All characters of both strings are the same except two indices.
        return s.charAt(fIndex)== goal.charAt(sIndex) && s.charAt(sIndex) == goal.charAt(fIndex);
    }
}