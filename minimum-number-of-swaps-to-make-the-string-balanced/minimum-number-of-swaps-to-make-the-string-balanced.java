class Solution {
    public int minSwaps(String s) {
        Stack<Character> st = new Stack();
        int cnt = 0;
        for(Character c : s.toCharArray()){
            if(c == '[') st.push(c);
            else{
                if(st.isEmpty()) cnt++;
                else st.pop();
            }
        }
        return (cnt + 1)/2;
    }
}