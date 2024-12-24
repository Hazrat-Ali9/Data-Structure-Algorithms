class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        map<int, int> mp;
        for(int i=0; i<n; i++) mp[hand[i]]++;
        while(!mp.empty()){
            int currCard = mp.begin()->first;
            for(int i=0; i<groupSize; i++){
                if(mp[currCard+i]==0) return false;
                mp[currCard+i]--;
                if(mp[currCard+i]<1) mp.erase(currCard+i);
            }
        }
        return true;
    }
};