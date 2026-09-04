class Solution {
public:
    int checkmin(int x,int n,vector<int>& nums){
        int ans=nums[x];
        for(int i=x+1;i<n;i++){
            if(nums[i]<ans){
                ans=nums[i];
            }
        }
        return ans;
    }
    int checkmax(int x,vector<int>& nums){
        int ans=nums[0];
        for(int i=1;i<x;i++){
            if(ans<nums[i]){
                ans=nums[i];
            }
        }
        return ans;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int anss=-1;
        for(int i=0;i<n;i++){
            int maxi=checkmax(i,nums);
            int mini=checkmin(i,n,nums);
            int res=maxi-mini;
            if(res<=k){
                anss=i;
                return anss;
            }
        }
        return anss;
    }
};