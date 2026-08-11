class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int seqSum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                seqSum+=nums[i];
            }
            else{
                break;
            }
        }
        unordered_set<int> st;
        for(int num:nums){
            st.insert(num);
        }

        while(st.count(seqSum)){
            seqSum++;
        }
        return seqSum;
    }
};