class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         int n=nums.size();
         int moves=0;
         int target=nums[n-1];
         for(auto x:nums){
           while(x!=target){
              x=x+1;
              moves++;
           }
         }
         return moves;
    }
};