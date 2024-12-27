class Solution{
public:
    vector<string> buildArray(vector<int> &target, int n){
        vector<string> ans;
        int i=0;
        for(int x : target){
            while(i < x-1){
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            ans.push_back("Push");
            i++;
        }
        return ans;
    }
};