class ParkingSystem {
public:
    vector<int> parking;
    ParkingSystem(int big, int medium, int small) {
        this->parking = vector<int>{big, medium, small};
    }
    bool addCar(int carType) {
        if(parking[carType-1] > 0){
            parking[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */