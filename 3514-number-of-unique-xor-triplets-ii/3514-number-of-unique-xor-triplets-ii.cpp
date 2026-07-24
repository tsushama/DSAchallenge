class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> ans;
        unordered_set<int>res;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                 res.insert(nums[i]^nums[j]);
            }
        }
        for(int x:res){
            for(int &num: nums){
                ans.insert(num^x);
            }
        }
        return ans.size();
    }
};