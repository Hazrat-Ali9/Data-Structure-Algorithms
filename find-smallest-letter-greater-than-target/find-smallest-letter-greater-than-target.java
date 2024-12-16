class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int l = 0, r = letters.length - 1, m;
        while(l <= r){
            m = (l+r)/2;
            if(letters[m] <= target) l = m+1;
            else r = m-1;
        }
        return l == letters.length ? letters[0] : letters[l];
    }
}