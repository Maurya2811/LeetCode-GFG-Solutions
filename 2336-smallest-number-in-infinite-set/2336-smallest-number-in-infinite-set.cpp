// 3 Approaches

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
      if(num>i)
        {
          return;
        }
       
        i=num;
        return;
    }
};

//2. Better Approach ( using Unordered Set and Min Heap)
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
