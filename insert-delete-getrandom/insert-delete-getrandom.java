class RandomizedSet {

    Set<Integer> s;
    public RandomizedSet() {
        s = new HashSet<>();
    }
    
    public boolean insert(int val) {
        if(s.contains(val)) return false;
        else{
            s.add(val);
            return true;
        }
    }
    
    public boolean remove(int val) {
        if(!s.contains(val)) return false;
        else{
            s.remove(val);
            return true;
        }
    }
    
    public int getRandom() {
        List<Integer> ls = new ArrayList<>(s);
        return ls.get(new Random().nextInt(ls.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */