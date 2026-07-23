class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=1; //2^0
        while(ans<=n){
            ans=ans*2; // ans=(ans<<1)
        }
        return ans;
    }
};