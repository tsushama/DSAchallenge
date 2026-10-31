class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int n=nums.size();
          int ans=1;
          int res=INT_MIN;
          int i=0;
          while(i<n){
                ans*=nums[i];
                res=max(res,ans);
                if(ans==0){
                    ans=1;
                }
                i++;
          }
          ans = 1;
          i = n - 1;
           while(i >= 0) {
            ans *= nums[i];
            res = max(res, ans);
            if(ans == 0) {
            ans = 1;
           }
           i--;
          }
         return res;
    }
};