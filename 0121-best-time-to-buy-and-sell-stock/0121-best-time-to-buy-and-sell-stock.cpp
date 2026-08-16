class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,j=1;
        int ans=0;
        while(j<n){
            while(prices[i]>prices[j]){
                i=j;
            }
            int res=prices[j]-prices[i];
            ans=max(ans,res);
            j++;
        }
        return ans;
    }
};