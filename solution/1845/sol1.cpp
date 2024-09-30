class SeatManager {
private:
    int seats = 0;
    priority_queue<int, vector<int>, greater<>> available;
public:
    SeatManager(int n) {
    }
    
    int reserve() {
        if (!available.empty()) {
            int seatNumber = available.top();
            available.pop();
            return seatNumber;
        }
        return ++seats;
    }
    
    void unreserve(int seatNumber) {
        available.push(seatNumber);
    }
};
