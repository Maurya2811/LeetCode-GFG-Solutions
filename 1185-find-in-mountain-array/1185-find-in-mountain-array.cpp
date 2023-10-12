
class Solution {
public:
   int n;
     int findPeakIndex(MountainArray &mountainArr){
                 
            int s=0,e=n-1;
            
            while(s<e){
                int mid = s + (e-s)/2;
                if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                    s= mid+1;
                }else{
                    e= mid;
                }
            }
            return s;
     }

     int binaryLeft(MountainArray &mountainArr, int target, int e){

         int s=0;
            
            while(s<=e){
                int mid = s + (e-s)/2;
                if(mountainArr.get(mid) == target){
                    return mid;
                }else if(mountainArr.get(mid)>target){
                    e= mid-1;
                }else{
                    s = mid+1;
                }
            }
            return -1;

     }
     int binaryRight(MountainArray &mountainArr, int target, int s){
             int e=n-1;
            
            while(s<=e){
                int mid = s + (e-s)/2;
                if(mountainArr.get(mid) == target){
                    return mid;
                }else if(mountainArr.get(mid)>target){
                    s= mid+1;
                }else{
                    e = mid-1;
                }
            }
            return -1;
     }


    int findInMountainArray(int target, MountainArray &mountainArr) {
         
         n = mountainArr.length();
         int peakIndex = findPeakIndex(mountainArr);
          cout<<peakIndex<<" ";
         int left = binaryLeft(mountainArr, target , peakIndex);
         int right = binaryRight(mountainArr, target,peakIndex);
          cout<<peakIndex<<"Left "<<left << " Right "<< right;

            // if(left ==-1){
            //      if(right ==-1)
            //      return -1;
            //      else
            //      return right;
            // }
            //  if(right ==-1){

            // }
            if(left !=-1 && right !=-1){
                return min(left , right);
            }
            
            return max(left, right);
    
    }
};