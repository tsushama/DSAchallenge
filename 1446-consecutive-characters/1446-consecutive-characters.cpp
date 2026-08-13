class Solution {
public:
    int maxPower(string s) {
        int n=s.length();
        if(n==1) return 1;
        int i=0,j=1;
        int res=0;
        while(j<n){
            if(s[j]!=s[j-1]){
                i=j;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};