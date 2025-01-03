class Solution {
public:
    int minSwaps(string s) {
        int stackSize = 0;
        for(char c : s){
            if(c == '[') stackSize++;
            else{
                if(stackSize > 0) stackSize--;
            }
        }
        return (stackSize + 1) / 2;
    }
};