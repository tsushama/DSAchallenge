class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
         int n=nums.size();
          unordered_map<int,bool> mp;
          for(int x:nums){
            if(x%k==0){
                mp[x/k]=true;
            }
          } 

          for(int i=1;i<=mp.size()+1;i++){
            if(mp[i]==false){
                return i*k;
            }
          }
          return mp.size()*k;
    }
};