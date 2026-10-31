class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int n=nums.size();
           int i=0;
           int ans=0;
           int res=INT_MIN;
           while(i<n){
               ans+=nums[i];
               res=max(res,ans);
               if(ans<=0){
                ans=0;
               }
               i++;
           }
          /* i=n-1;
           ans=1;
           while(i>=0){
            ans+=nums[i]
           }*/
           return res;
    }
};