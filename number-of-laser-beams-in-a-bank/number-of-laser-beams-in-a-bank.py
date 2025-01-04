class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0, prev = 0;
        for(String s : bank){
            int cnt = 0;
            for(Character c : s.toCharArray()){
                if(c == '1') cnt++;
            }
            if(cnt != 0){
                ans += cnt*prev;
                prev = cnt;
            }
        }
        return ans;
    }
}