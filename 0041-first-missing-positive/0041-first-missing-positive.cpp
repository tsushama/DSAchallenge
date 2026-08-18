class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int x:nums){
            mp[x]++;
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
             if(mp[i]==0){
                return i;
             }
        }
        return n+1;
    }
};