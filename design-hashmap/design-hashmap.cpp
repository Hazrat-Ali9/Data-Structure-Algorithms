class MyHashMap {
public:
    vector<int> mp;
    MyHashMap() {
        mp.resize(1e6+1);
        fill(mp.begin(), mp.end(), -1);
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
    }
};

// Design Hashmap