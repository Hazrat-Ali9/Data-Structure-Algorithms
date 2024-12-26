class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int windowSum = 0, zeroSum = 0, mxWindowSum = 0, n = customers.size();
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0) zeroSum += customers[i];
            if(i < minutes) windowSum += (grumpy[i] == 1 ? customers[i] : 0);
            else{
                windowSum += (grumpy[i]==1 ? customers[i] : 0) - (grumpy[i-minutes]==1 ? customers[i-minutes] : 0);
            }
            mxWindowSum = max(mxWindowSum, windowSum);
        }
        return mxWindowSum + zeroSum;
    }
};