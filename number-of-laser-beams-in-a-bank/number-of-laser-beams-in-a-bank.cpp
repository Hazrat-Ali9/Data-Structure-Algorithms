class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, cnt = 0;
        for(int i=0; i<bank.size(); i++){
            int cnt1 = 0;
            for(int j=0; j<bank[i].size(); j++){
                if(bank[i][j] == '1') cnt1++;
            }
            if(cnt1 != 0){
                ans += cnt * cnt1;
                cnt = cnt1;
            }
        }
        return ans;
    }
};