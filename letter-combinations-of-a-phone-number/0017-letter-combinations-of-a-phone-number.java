class Solution {
    String[] mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    List<String> ans = new ArrayList<String>();
    public List<String> letterCombinations(String digits) {
        if(digits.isEmpty()) return ans;
        helper(0, new StringBuilder(), digits);
        return ans;
    }
    void helper(int i, StringBuilder combi, String digits){
        if(i == digits.length()){
            ans.add(combi.toString());
            return;
        }
        for(char x : mp[digits.charAt(i)-'2'].toCharArray()){
            combi.append(x);
            helper(i+1, combi, digits);
            combi.deleteCharAt(combi.length()-1);
        }
    }
}