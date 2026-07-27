class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> minh;
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
            if(minh.size()>2){
                minh.pop();
            }
        }
        int ans=1;
        while(!minh.empty()){
            ans=ans*(minh.top()-1);
            minh.pop();
        }
        return ans;
    }
};