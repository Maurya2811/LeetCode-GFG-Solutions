//Brute Force
/*
class MyHashSet {
public:
    vector<bool> v;
    MyHashSet() {
      v.resize(1000001,false);
    }
    
    void add(int key) {
        v[key]=true;
    }
    
    void remove(int key) {
       v[key]=false;
    }
    
    bool contains(int key) {
      return v[key];
    }
};
*/

class MyHashSet {
public:
  int M;
    vector<list<int>> bucket;
    MyHashSet() {
      bucket.resize(10010);
        M=10010;
    }
    
    int getIndex(int key){
        return key%M;
    }
    
    void add(int key) {
        int i= getIndex(key);
         auto itr =find(bucket[i].begin(),bucket[i].end(),key);
        if(itr==bucket[i].end()){
            bucket[i].push_back(key);
        }
    }
    
    void remove(int key) {
        int i= getIndex(key);
      auto itr =find(bucket[i].begin(),bucket[i].end(),key);
        if(itr!=bucket[i].end()){
            bucket[i].erase(itr);
        }
    }
    
    bool contains(int key) {
        int i= getIndex(key);
      auto itr =find(bucket[i].begin(),bucket[i].end(),key);
      return itr!=bucket[i].end();
    }

};