class MyHashSet {
    int[] s;
    public MyHashSet() {
        s = new int[1000000+1];
    }
    public void add(int key) {
        s[key] = 1;
    }
    public void remove(int key) {
        s[key] = 0;
    }
    public boolean contains(int key) {
        return s[key]==1;
    }
}

// Design hashset