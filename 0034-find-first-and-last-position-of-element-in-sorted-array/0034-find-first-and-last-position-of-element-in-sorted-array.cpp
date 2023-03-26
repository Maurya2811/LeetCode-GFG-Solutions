class Solution {
public:
    vector<int> searchRange(vector<int>& v, int key)
 {
        int l=0,r=v.size()-1,m;
        vector<int> v1(2,-1);
  while(l<=r)
  {
    m=l+(r-l)/2;
     if(v[m]==key)
     { 
           v1[0]=m;
           r=m-1;     
     }
     else if(v[m]>key)
        r=m-1;
     else
        l=m+1;
   }

  r=v.size()-1;
  while(l<=r)
  {
      m=l+(r-l)/2;
       if(v[m]==key)
        { 
        //   if(m+1<=r && v[m+1]==key)
        //     l=m+1;
        //   else
            v1[1]=m;
            l=m+1;      
        }
        else if(v[m]>key)
          r=m-1;
        else
          l=m+1;
  }
    return v1;
 }
};