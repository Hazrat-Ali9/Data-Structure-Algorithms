class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        int[] sortedPeople = Arrays.copyOf(people, people.length);
        Arrays.sort(sortedPeople);
        Arrays.sort(flowers, (a, b) -> Arrays.compare(a, b));
        Map<Integer, Integer> mp = new HashMap<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int i=0;
        for(int person : sortedPeople){
            while(i < flowers.length && flowers[i][0] <= person){
                pq.add(flowers[i][1]);
                i++;
            }
            while(!pq.isEmpty() && pq.peek() < person) pq.remove();
            mp.put(person, pq.size());
        }
        int[] ans = new int[people.length];
        for(int j=0; j<people.length; j++) ans[j] = mp.get(people[j]);
        return ans;
    }
}