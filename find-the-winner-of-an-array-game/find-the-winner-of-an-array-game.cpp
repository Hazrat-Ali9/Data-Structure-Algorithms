class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = arr[0];
        queue<int> q;
        for(int i=1; i<arr.size(); i++){
            mx = max(mx, arr[i]);
            q.push(arr[i]);
        }
        int curr = arr[0], streak = 0;
        while(!q.empty()){
            int opponent = q.front(); q.pop();
            if(curr > opponent){
                q.push(opponent);
                streak++;
            }
            else{
                q.push(curr);
                curr = opponent;
                streak = 1;
            }
            if(streak == k or curr == mx) return curr;
        }
        return -1;
    }
};