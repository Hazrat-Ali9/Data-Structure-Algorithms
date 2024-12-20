class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> cnt = new HashMap();
        for(String word : s1.split(" ")) cnt.put(word, cnt.getOrDefault(word, 0)+1);
        for(String word : s2.split(" ")) cnt.put(word, cnt.getOrDefault(word, 0)+1);
        List<String> ans = new LinkedList();
        for(String word : cnt.keySet()){
            if(cnt.get(word) == 1) ans.add(word);
        }
        return ans.toArray(new String[ans.size()]);
    }
}