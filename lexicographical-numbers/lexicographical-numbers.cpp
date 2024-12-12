class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int currNum = 1;
        for(int i=0; i<n; i++){
            ans.push_back(currNum);
            if(currNum*10 <= n) currNum *= 10;
            else{
                while(currNum%10 == 9 || currNum >= n) currNum /= 10;
                currNum++;
            }
        }
        return ans;
    }
};