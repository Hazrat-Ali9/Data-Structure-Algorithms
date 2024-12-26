class UndergroundSystem {
    Map<Integer, CheckInInfo> checkIns;
    Map<String, TravelInfo> travelTimes;
    public UndergroundSystem() {
        checkIns = new HashMap<>();
        travelTimes = new HashMap<>();
    }
    public void checkIn(int id, String stationName, int t) {
        checkIns.put(id, new CheckInInfo(stationName, t));
    }
    public void checkOut(int id, String stationName, int t) {
        CheckInInfo checkInfo = checkIns.remove(id);
        String travel = checkInfo.name + "," + stationName;
        int travelTime = t - checkInfo.time;
        if(travelTimes.containsKey(travel)){
            TravelInfo travelInfo = travelTimes.get(travel);
            travelInfo.totalTime += travelTime;
            travelInfo.count++;
        }
        else{
            travelTimes.put(travel, new TravelInfo(travelTime, 1));
        }
    }
    public double getAverageTime(String startStation, String endStation) {
        String travel = startStation+","+endStation;
        TravelInfo info = travelTimes.get(travel);
        return (double) info.totalTime / info.count;
    }
    class CheckInInfo{
        String name;
        int time;
        CheckInInfo(String name, int time){
            this.name = name;
            this.time = time;
        }
    }
    class TravelInfo{
        int totalTime;
        int count;
        TravelInfo(int totalTime, int count){
            this.totalTime = totalTime;
            this.count = count;
        }
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */