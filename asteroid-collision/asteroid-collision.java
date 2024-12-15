class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> s = new Stack<Integer>();
        for(int x : asteroids){
            boolean flag = true;
            while(!s.isEmpty() && s.peek()>0 && x<0){
                if(Math.abs(x) > Math.abs(s.peek())){
                    s.pop();
                    continue;
                }
                else if(Math.abs(x) == Math.abs(s.peek())) s.pop();
                flag = false;
                break;
            }
            if(flag) s.push(x);
        }
        int[] ans = new int[s.size()];
        for(int i=s.size()-1; i>=0; i--){
            ans[i] = s.peek();
            s.pop();
        }
        return ans;
    }
}