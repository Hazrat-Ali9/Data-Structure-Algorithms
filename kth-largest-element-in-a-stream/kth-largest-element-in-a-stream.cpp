class KthLargest {
public:
    vector<int> stream;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) stream.push_back(num);
        sort(stream.begin(), stream.end());
    }
    int add(int val) {
        int index = getIndex(val);
        stream.insert(stream.begin()+index, val);
        return stream[stream.size()-k];
    }
    int getIndex(int val){
        int l=0, r=stream.size()-1;
        while(l <= r){
            int m = (l+r)/2;
            if(stream[m] == val) return m;
            if(stream[m] > val) r = m-1;
            else l = m+1;
        }
        return l;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */