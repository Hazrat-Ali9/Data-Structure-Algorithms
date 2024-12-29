class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> arrival;
        for(int i=0; i<dist.size(); i++) arrival.push_back((float)dist[i]/speed[i]);
        sort(arrival.begin(), arrival.end());
        int ans = 0;
        for(int i=0; i<arrival.size(); i++){
            if(arrival[i] <= i) break;
            ans++;
        }
        return ans;
    }
};