class Solution {
    public int largestAltitude(int[] gain) {
        int currAlt = 0, mxAlt = 0;
        for(int x : gain){
            currAlt += x;
            mxAlt = Math.max(mxAlt, currAlt);
        }
        return mxAlt;
    }
}