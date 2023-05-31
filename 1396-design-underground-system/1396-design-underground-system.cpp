class UndergroundSystem {
public:
    unordered_map< int, pair<string,int>> checkin_map; 
    unordered_map< string, pair<int,int>> checkout_map;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin_map[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string route = checkin_map[id].first + "_" + stationName ;
        
        int total_time= t - checkin_map[id].second ;
        
        checkout_map[route].first+=total_time;
        checkout_map[route].second++;
        
        checkin_map.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation ;
        
        int total_time = checkout_map[route].first ;
        int count = checkout_map[route].second ;
        
        return double(total_time)/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */