class Solution {
public:
    int smallestNumber(int n, int t) {
         int ans;
         for(int i=n;i<10*n;i++){
            int res=i;
            int product=1;
            while(res>0){
               product*=res%10;
               res=res/10;
            }
            if(product%t==0){
                ans=i;
                break;
            }
         }
         return ans;
    }
};