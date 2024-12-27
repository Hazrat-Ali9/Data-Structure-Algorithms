class CustomStack {
private:
    vector<int> stArray, incrArray;
    int topIndex;
public:
    CustomStack(int maxSize) {
        stArray.resize(maxSize);
        incrArray.resize(maxSize);
        topIndex = -1;
    }
    
    void push(int x) {
        if(topIndex < (int)(stArray.size())-1) stArray[++topIndex] = x;
    }
    
    int pop() {
        if(topIndex < 0) return -1;
        int ans = stArray[topIndex] + incrArray[topIndex];
        if(topIndex > 0) incrArray[topIndex-1] += incrArray[topIndex];
        incrArray[topIndex--] = 0;
        return ans;
    }
    
    void increment(int k, int val) {
        if(topIndex >= 0){
            int incrIndex = min(topIndex, k-1);
            incrArray[incrIndex] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */