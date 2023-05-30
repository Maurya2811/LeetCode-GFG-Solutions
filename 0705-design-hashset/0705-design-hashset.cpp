class MyHashSet {
public:
    int v[10000000];
    MyHashSet() {
      memset(v,-1,sizeof(v));
    }
    
    void add(int key) {
        v[key]=key;
    }
    
    void remove(int key) {
       v[key]=-1;
    }
    
    bool contains(int key) {
        if(v[key]!=-1)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */