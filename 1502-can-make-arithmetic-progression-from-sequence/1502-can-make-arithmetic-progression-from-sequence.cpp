//Approach-1 (Using Sorting (O(nlogn))
/*
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        
        int d = arr[1] - arr[0];
        
        for(int i = 2; i<n; i++) {
            if(arr[i] - arr[i-1] != d)
                return false;
        }
        
        return true;
    }
};
*/


//Approach-2 (Using Mathematival AP property - O(n) Time, O(n) Space))
// /*
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        
        unordered_set<int> st(begin(arr), end(arr));
        
        int min_el = *min_element(begin(arr), end(arr)); // a
        int max_el = *max_element(begin(arr), end(arr)); // a+(n-1)*d
                                                         // -
                                                        // ---------------------
                                                        //   (n-1)*d = constt
                                                       // d = constt /(n-1)
                         // Since common differece never be fractional that's why 
                         // n-1 must be multiple of diff( max_el - min_el )
        
        if((max_el - min_el)%(n-1)!=0)
            return false;
        
        int d = (max_el - min_el)/(n-1);
        
        int i = 0; 
        //a0 , a0+d , a0 + 2d
        
        while(i < n) {
            int num = min_el + i*d;
            if(st.find(num) == st.end())
                return false;
            
            i++;
        }
        
        return true;
    }
};
// */
// Approach-3 (Using Mathematival AP property - O(n) Time, O(1) Space))

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        
        
        
        int min_el = *min_element(begin(arr), end(arr)); // a
        int max_el = *max_element(begin(arr), end(arr)); // a+(n-1)*d
                                                         // -
                                                        // ---------------------
                                                        //   (n-1)*d = constt
                                                       // d = constt /(n-1)
                         // Since common differece never be fractional that's why 
                         // n-1 must be multiple of diff( max_el - min_el )
        
        if((max_el - min_el)%(n-1)!=0)
            return false;
        
        int d = (max_el - min_el)/(n-1);
    
        int i = 0; 
        //a0 , a0+d , a0 + 2d
        
        while(i < n) {
           int val = arr[i];
            
            if(val == min_el + i*d )
                i++;
           else{ 
              if((val-min_el)%d!=0)
                return false;
            
               int j=(val-min_el)/d ;
            
              if(arr[j]==val)
                  return false;
               
               swap(arr[i],arr[j]);
          }
        }
        
        return true;
    }
};
