class Solution {
public:
    bool checkDivisibility(int n) {
         int temp=n;
         int sum=0,product=1;
         while(n>0){
              sum+=n%10;
              product*=n%10;
              n=n/10;
         }
         int res=product+sum;
         if(temp%res==0){
            return true;
         }
         return false;
    }
};