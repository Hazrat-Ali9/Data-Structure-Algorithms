class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int l = 0, r = arr.length-1;
        while(l < r){
            int m = (l+r)/2;
            if(arr[m] < arr[m+1]) l = m+1;
            else r = m;
        }
        return l;
    }
}