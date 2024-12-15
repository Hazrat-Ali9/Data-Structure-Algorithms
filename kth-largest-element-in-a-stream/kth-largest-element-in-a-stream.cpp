class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int x : nums) pq.push(x);
        while(pq.size() > k) pq.pop();
    }
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

// Largest element