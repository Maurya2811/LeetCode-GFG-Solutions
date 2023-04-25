// 3 Approaches
/*
// 1 Brute Force ( Using bool vector)
class SmallestInfiniteSet {
public:
    vector<bool>  flag;
    int i;
    
    SmallestInfiniteSet() {
        i=1;
        flag= vector<bool>(1000,true);
    }
    
    int popSmallest() {
        int result =i; 
        flag[i]=false;
        while(flag[i]!=true){
            i++;
        }
        return result;
    }
    
    void addBack(int num) {
         flag[num]=true;
      // if(num>i)
      //     return;
      //  else 
      //  { i=num;
      //    return;
      //  }
        if(num<i)
            i=num;
    }
};

*/
//2. Better Approach ( using Unordered Set and Min Heap)
// /*
 class SmallestInfiniteSet {
public:
     unordered_set<int>set;
     priority_queue<int,vector<int>, greater<int> > pq; 
     int currSmallest;
     
    SmallestInfiniteSet() {
        currSmallest=1;
    }
    
    int popSmallest() {
     int result;
          if(!pq.empty()){
                    result=pq.top();
                    pq.pop();
                    set.erase(result);
              }
            else{
                result=currSmallest;
                currSmallest++;
            }
     return result;
    }
    
    void addBack(int num) {
        if(num>=currSmallest || set.find(num)!=set.end())
            return ;
        set.insert(num);
        pq.push(num);
    }
};
 
  // */
// 3. Optimal Approach (using Ordered Set only)
/*
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        
    }
    
    void addBack(int num) {
        
    }
};
 
 */
