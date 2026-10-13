class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
         int n=nums.size();
         int m=(n+1)/2;
         vector<long long> sq;
           for (int x:nums){
            sq.push_back(1LL*x*x);
              }
        sort(sq.begin(), sq.end());

         vector<int> large;
         vector<int> small;
         for(int i=n-1;i>=n/2;i--){
            large.push_back(sq[i]);
         }
         for(int i=0;i<n/2;i++){
            small.push_back(sq[i]);
         }
         long long res=0;
          for (int i = 0; i < n / 2; i++) {
           res += 1LL * large[i];
           res -= 1LL * small[i];
          }

          if (n % 2 != 0) {
             res += 1LL * large[n / 2];
             }
        return res;
    }
};