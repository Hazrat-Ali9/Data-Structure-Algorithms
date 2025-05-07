class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int width = abs(sx-fx), hight = abs(sy-fy);
        if(width==0 && hight==0 && t==1) return false;
        return t>=max(width, hight);
    }
};

// Detemine if a cell is rechable at a given time