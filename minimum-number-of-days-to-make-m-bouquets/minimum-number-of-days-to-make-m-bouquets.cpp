class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=0, r=*max_element(bloomDay.begin(), bloomDay.end());
        int mnDays = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(getNumOfBouquets(bloomDay, mid, k) >= m){
                mnDays = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return mnDays;
    }
    int getNumOfBouquets(vector<int> &bloomDay, int m, int k){
        int numOfBouquets = 0, cnt = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= m) cnt++;
            else cnt = 0;
            if(cnt == k){
                numOfBouquets++;
                cnt = 0;
            }
        }
        return numOfBouquets;
    }
};