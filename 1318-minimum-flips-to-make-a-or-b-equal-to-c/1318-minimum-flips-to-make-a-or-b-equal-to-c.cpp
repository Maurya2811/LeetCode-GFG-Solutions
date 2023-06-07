class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        while( a || b || c ){
            if( (c & 1) ==1 ){
                if( (a&1)==0 && (b&1)==0){
                    flip++;
                }
            
            }
            else{
                if((a&1) == 1)
                    flip++;
                if((b&1) == 1)
                    flip++;
            }
//             flip += (a&1) + (b&1)
            a>>=1 ; b>>=1 ; c>>=1;
        }
        return flip;
    }
};