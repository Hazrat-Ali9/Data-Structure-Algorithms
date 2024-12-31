class SeatManager {

    PriorityQueue<Integer> pq= new PriorityQueue();
    public SeatManager(int n) {
        for(int i=1; i<=n; i++) pq.offer(i);
    }
    
    public int reserve() {
        int seatNumber = pq.poll();
        return seatNumber;
    }
    
    public void unreserve(int seatNumber) {
        pq.offer(seatNumber);
    }
}

// Seat Reservation manager