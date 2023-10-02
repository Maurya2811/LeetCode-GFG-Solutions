class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice_count=0;
        int bob_count=0;
          int n=colors.length();
          if(n<3){
              return false;
          }
        for(int i=0;i<n-2;i++){
            
              if(colors[i]==colors[i+1] && colors[i+1]==colors[i+2]){
                if(colors[i]=='A')
                   alice_count++;
                else
                   bob_count++;
              }
            }
            
            // if(colors[i]=='A'){
            //   if(colors[i+1]==colors[i+2] && colors[i+1]=='A'){
            //     alice_count++;
            //   }
            // }
            // else if(colors[i]=='B'){
            //      if( colors[i+1]==colors[i+2]&&colors[i+1]=='B'){
            //       bob_count++;
            //    }
            // }
            // }
        
        return alice_count>bob_count;
    }
};