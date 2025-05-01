class Solution {
    boolean isVowel(Character c){
        return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    public String sortVowels(String s) {
        ArrayList<Character> temp = new ArrayList<>();
        for(char c : s.toCharArray()){
            if(isVowel(c)) temp.add(c);
        }
        Collections.sort(temp);
        StringBuilder ans = new StringBuilder();
        for(int i=0, j=0; i<s.length(); i++){
            if(isVowel(s.charAt(i))) ans.append(temp.get(j++));
            else ans.append(s.charAt(i));
        }
        return ans.toString();
    }
}