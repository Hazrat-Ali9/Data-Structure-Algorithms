class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        if(mx - mn == 0) return true;
        if((mx - mn) % (n-1) != 0) return false;
        int diff = (mx - mn) / (n-1);
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            if((arr[i] - mn) % diff != 0) return false;
            s.insert(arr[i]);
        }
        return s.size() == n;
    }
};