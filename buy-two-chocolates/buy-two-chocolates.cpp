class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int small = INT_MAX, secSmall = INT_MAX;
        for(int x : prices){
            if(x < small){
                secSmall = small;
                small = x;
            }
            else secSmall = min(secSmall, x);
        }
        return small+secSmall<=money ? money-small-secSmall : money;
    }
};