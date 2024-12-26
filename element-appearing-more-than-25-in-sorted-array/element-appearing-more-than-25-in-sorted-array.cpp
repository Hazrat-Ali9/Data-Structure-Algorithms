class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size()/4;
        for(int i=0; i<arr.size()-sz; i++){
            if(arr[i] == arr[i+sz]) return arr[i];
        }
        return -1;
    }
};