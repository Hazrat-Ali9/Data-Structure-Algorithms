class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int candidate1=Integer.MIN_VALUE, candidate2=Integer.MIN_VALUE, life1=0, life2=0;
        for(int x : nums){
            if(candidate1 == x) life1++;
            else if(candidate2 == x) life2++;
            else if(life1 == 0){
                candidate1 = x;
                life1 = 1;
            }
            else if(life2 == 0){
                candidate2 = x;
                life2 = 1;
            }
            else{
                life1--;
                life2--;
            }
        }
        life1 = 0;
        life2 = 0;
        for(int x : nums){
            if(x == candidate1) life1++;
            if(x == candidate2) life2++;
        }
        List<Integer> ans = new ArrayList<>();
        if(life1 > nums.length/3) ans.add(candidate1);
        if(life2 > nums.length/3) ans.add(candidate2);
        return ans;
    }
}