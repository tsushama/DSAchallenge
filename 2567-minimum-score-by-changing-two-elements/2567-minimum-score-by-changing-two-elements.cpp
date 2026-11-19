class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
         int one=abs(nums[n-2]-nums[1]);
         int two=abs(nums[n-3]-nums[0]);
         int three=abs(nums[n-1]-nums[2]);
         int high=min({
            one,two,three});
         return high;
    }
};