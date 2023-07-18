// Brute force 
//  TLE
/*
class LRUCache {
public:
    vector<pair<int,int>> cache;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                int value=cache[i].second;
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return value;
            }
            
        }
        return -1;
    }
    
    void put(int key, int value) {
         for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return;
            }
            
    }
         if(cache.size()>=n){
               cache.erase(cache.begin());
             cache.push_back({key,value});
         }else{
             cache.push_back({key,value});
         }
        
    }
};

*/

// Using STL List

class LRUCache {
public:
    list<int> dll;
    unordered_map<int,pair<list<int>::iterator,int>>map;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void makeRecentlyUsed(int key){
        
       dll.erase( map[key].first );
        dll.push_front(key);
        map[key].first = dll.begin();
    }
    
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
        }
      makeRecentlyUsed( key);        
        return map[key].second;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            
            map[key].second=value;
            makeRecentlyUsed(key);
        }else{
            dll.push_front(key);
            map[key] = {dll.begin(),value};
            n--;
        }
        if(n<0){
            int keyToDel = dll.back();
            map.erase(keyToDel);
            dll.pop_back();
            n++;
        }
    }
};

