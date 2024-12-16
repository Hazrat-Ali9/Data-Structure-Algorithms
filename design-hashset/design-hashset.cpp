class MyHashSet {
public:
    vector<int> s;
    MyHashSet() {
        s.resize(1e6+1, 0);
    }
    void add(int key) {
        s[key] = 1;
    }
    void remove(int key) {
        s[key] = 0;
    }
    bool contains(int key) {
        return s[key];
    }
};

// Design hashset