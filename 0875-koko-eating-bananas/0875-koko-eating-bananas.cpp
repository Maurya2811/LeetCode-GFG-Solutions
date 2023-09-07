class Solution {
public:
    bool canEat(vector<int>& piles,int &h, int banana){
        int hour =0;
        for( int &x:piles){
            
            hour += x/banana;
            if(x%banana){
                hour++;
            }
            if(hour>h){
                return false;
            }
        }
        return true;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi =0;
        for( int &x: piles){
            if(x>maxi){
                maxi =x;
            }
        }
        
        int start =1 , end = maxi;
        while(start<end){
            int mid = start + (end-start)/2;
            
            if(canEat(piles,h,mid)){
                end = mid;   
            }else{
                start = mid+1;
            }
        }
    
        return end;
    }
};