class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<int, int>> travelTimes;
    UndergroundSystem() {
        
    }
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = make_pair(stationName, t);
    }    
    void checkOut(int id, string stationName, int t) {
        auto checkInInfo = checkIns[id];
        checkIns.erase(id);
        string travel = checkInInfo.first + "," + stationName;
        int travelTime = t - checkInInfo.second;
        if(travelTimes.find(travel) != travelTimes.end()){
            travelTimes[travel].first += travelTime;
            travelTimes[travel].second++;
        }
        else{
            travelTimes[travel] = make_pair(travelTime, 1);
        }
    }
    double getAverageTime(string startStation, string endStation) {
        string travel = startStation + "," + endStation;
        auto travelTime = travelTimes[travel];
        return (double) travelTime.first/travelTime.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */