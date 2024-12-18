class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[1]-b[1]);
        int cnt = 0, curr = Integer.MIN_VALUE;
        for(int[] x : pairs){
            if(x[0] > curr){
                cnt++;
                curr = x[1];
            }
        }
        return cnt;
    }
}