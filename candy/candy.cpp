class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            //for increasing slope
            int peek = 0;
            while(ratings[i] > ratings[i-1]){
                peek++;
                candy += peek;
                i++;
                if(i == n) return candy;
            }
            //for decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peek, valley);
        }
        return candy;
    }
};