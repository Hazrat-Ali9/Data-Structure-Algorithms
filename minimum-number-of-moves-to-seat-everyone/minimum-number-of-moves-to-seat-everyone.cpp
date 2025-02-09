class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int mxPos = max(findMax(seats), findMax(students));
        vector<int> diff(mxPos, 0);
        // Count the available seats at each position
        for(int x : seats) diff[x-1]++;
        // Remove a seat for each student at that position
        for(int x : students) diff[x-1]--;
        int moves = 0, unMatch = 0;
        for(int x : diff){
            moves += abs(unMatch);
            unMatch += x;
        }
        return moves;
    }
    int findMax(vector<int>arr){
        int mx = 0;
        for(int x : arr){
            if(x > mx) mx = x;
        }
        return mx;
    }
};