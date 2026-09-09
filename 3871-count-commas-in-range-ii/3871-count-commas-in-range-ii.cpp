class Solution {
public:
    long long countCommas(long long n) {
        long long lower=1000;
        int comma=1;
        long long ans=0;
        while(lower<=n){
            long long upper=(lower*1000)-1;
            if(upper>n) upper=n;
            long long countnum=(upper-lower)+1;
            ans+=countnum*comma;
            lower=lower*1000;
            comma+=1;
        }
        return ans;
    }
};