class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minfromind(n);
        int mine=INT_MAX;
         for(int i=n-1;i>=0;i--){
          mine=min(mine,nums[i]);
          minfromind[i]=mine;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
             maxi=max(maxi,nums[i]);
            int mini=minfromind[i];
            int res=maxi-mini;
            if(res<=k){ 
                return i;
            } 
        }
        return -1;
    }
};