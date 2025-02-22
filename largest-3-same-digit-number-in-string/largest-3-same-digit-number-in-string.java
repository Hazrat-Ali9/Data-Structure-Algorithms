class Solution {
    public String largestGoodInteger(String num) {
        char mxDigit = ' ';
        for(int i=0; i<=num.length()-3; i++){
            if(num.charAt(i)==num.charAt(i+1) && num.charAt(i)==num.charAt(i+2)){
                mxDigit = (char) Math.max(mxDigit, num.charAt(i));
            }
        }
        return mxDigit==' ' ? "" : new String(new char[]{mxDigit, mxDigit, mxDigit});
    }
}