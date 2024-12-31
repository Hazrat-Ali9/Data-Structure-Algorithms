class SeatManager {
public:
    int marker;
    priority_queue<int, vector<int>, greater<int>> availableSeats;
    SeatManager(int n) {
        marker = 1;
    }
    
    int reserve() {
        if(!availableSeats.empty()){
            int seatNumber = availableSeats.top();
            availableSeats.pop();
            return seatNumber;
        }
        int seatNumber = marker;
        marker++;
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        availableSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */