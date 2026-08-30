class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
         int maxi=INT_MIN;
         int maxind=-1;
         int mini=INT_MAX;
         int minind=-1;
         for(int i=0;i<n;i++){
             if(nums[i]>maxi){
                maxi=nums[i];
                maxind=i;
             }
            if(nums[i] < mini){
                mini=nums[i];
                minind=i;
             }
         }
        int bothfromleft=max(maxind,minind)+1;
        int bothfromright=n-min(maxind,minind);
        int oneleftoneright= 
        min(maxind,minind)+ 1 
        + n - max(maxind,minind);

        return min({bothfromleft,bothfromright,oneleftoneright});
    }
};