class Solution {
    public int getWinner(int[] arr, int k) {
        int mx = arr[0], curr = arr[0], streak = 0;
        for(int i=1; i<arr.length; i++) mx = Math.max(mx, arr[i]);
        for(int i=1; i<arr.length; i++){
            int opponent = arr[i];
            if(curr > opponent){
                streak++;
            }
            else{
                curr = opponent;
                streak=1;
            }
            if(streak==k || mx==curr) return curr;
        }
        return -1;
    }
}