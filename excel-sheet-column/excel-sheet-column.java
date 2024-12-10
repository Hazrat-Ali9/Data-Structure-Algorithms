class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder ans = new StringBuilder();
        while(columnNumber > 0){
            columnNumber--;
            ans.append((char)((columnNumber)%26 + 'A'));
            columnNumber /= 26;
        }
        return ans.reverse().toString();
    }
}