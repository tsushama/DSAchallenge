class Solution {
public:
    bool ispresent(int x,vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                return true;
            }
        }
        return false;
    }
    vector<int> findMissingElements(vector<int>& nums) {
         vector<int> ans;
         sort(nums.begin(),nums.end());
         int n=nums.size();
         int mx=nums[n-1];
         int mn=nums[0];
         for(int i=mn;i<=mx;i++){
            if(!ispresent(i,nums)){
                ans.push_back(i);
            }
         }
       return ans;
    }
};