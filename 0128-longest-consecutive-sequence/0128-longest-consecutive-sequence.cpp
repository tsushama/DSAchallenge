class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt=1,res=1;
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        sort(nums.begin(),nums.end());
         set<int> st(nums.begin(),nums.end());
         vector<int> v(st.begin(), st.end());
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]==v[i]+1){
                cnt++;
            }
            else{
                cnt=1;
            }
            res=max(res,cnt);
        }
        return res;
    }
};