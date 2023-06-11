class SnapshotArray {
public:
   int snap_id;

   vector<vector<pair<int,int>>> arr ;
    
    
    
    SnapshotArray(int length) {
        snap_id=0;
        arr.resize(length);
        for(int i=0;i<length;i++){
            arr[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        arr[index].push_back({snap_id,val});
    }
    
    int snap() {    
      return snap_id++;  
    }
    
    int get(int index, int snap_Id) {     
       int s=0 , e = arr[index].size()-1;
        int result=0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[index][mid].first <= snap_Id){
               result = arr[index][mid].second;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return result;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */