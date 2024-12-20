class Solution {
    public String reorganizeString(String s) {
        var cnt = new int[26];
        for(char c : s.toCharArray()) cnt[c-'a']++;
        var pq = new PriorityQueue<int[]>((a, b) -> Integer.compare(b[1], a[1]));
        for(int i=0; i<26; i++){
            if(cnt[i] > 0) pq.offer(new int[] {i+'a', cnt[i]});
        }
        var ans = new StringBuilder();
        while(!pq.isEmpty()){
            var first = pq.poll();
            if(ans.length()==0 || first[0] != ans.charAt(ans.length()-1)){
                ans.append((char)first[0]);
                if(--first[1] > 0) pq.offer(first);
            }
            else{
                if(pq.isEmpty()) return "";
                var second = pq.poll();
                ans.append((char) second[0]);
                if(--second[1] > 0) pq.offer(second);
                pq.offer(first);
            }
        }
        return ans.toString();
    }
}