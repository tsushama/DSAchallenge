class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odds=0,i=1,cnt=1;
        int evens=0,j=2;
        while(cnt<=n){
            odds+=i;
            evens+=j;
            cnt++;
            i+=2;
            j+=2;
        }
        return gcd(odds,evens);
    }
};