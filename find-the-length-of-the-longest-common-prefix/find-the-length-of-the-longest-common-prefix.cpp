class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr1Prefixes;
        
        for(int val : arr1){
            while(!arr1Prefixes.count(val) && val>0){
                // Insert current value as a prefix
                arr1Prefixes.insert(val);
               
                val /= 10;
            }
        }
        int longestPrefix = 0;
       
        for(int val : arr2){
            while(!arr1Prefixes.count(val) && val > 0){
                
                val /= 10;
            }
            if(val > 0){
                
                longestPrefix = max(longestPrefix, static_cast<int>(log10(val)+1));
            }
        }
        return longestPrefix;
    }
};