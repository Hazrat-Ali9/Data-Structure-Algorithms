class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length, m = matrix[0].length;
        if(n == 0 || m == 0) return false;
        int l = 0, r = n*m-1;
        while(l <= r){
            int mid = (l+r)/2;
            int val = matrix[mid/m][mid%m];
            if(val == target) return true;
            if(val > target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
}