class Solution {
public:
    int maxProduct(int n) {
        int ans=1;
        vector<int>res;
        while(n>0){
          res.push_back(n%10);
          n=n/10;
        }
        int x=res.size();
        sort(res.begin(),res.end());
        int i=x-1;
        int cnt=0;
        while(cnt<2){
            ans=ans*res[i];
            cnt++;
            i--;
        }
        return ans;
    }
};