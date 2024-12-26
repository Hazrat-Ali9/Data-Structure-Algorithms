

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 1, r = n-2;
        while(l != r){
            int ind = (l+r)/2;
            if(mountainArr.get(ind) < mountainArr.get(ind+1)) l = ind+1;
            else r = ind;
        }
        int peekIndex = l;
        l = 0, r = peekIndex;
        while(l != r){
            int ind = (l+r)/2;
            if(mountainArr.get(ind) < target) l = ind+1;
            else r = ind;
        }
        if(mountainArr.get(l) == target) return l;
        l = peekIndex+1, r = n-1;
        while(l != r){
            int ind = (l+r)/2;
            if(mountainArr.get(ind) > target) l = ind+1;
            else r = ind;
        }
        if(mountainArr.get(l) == target) return l;
        return -1;
    }
};