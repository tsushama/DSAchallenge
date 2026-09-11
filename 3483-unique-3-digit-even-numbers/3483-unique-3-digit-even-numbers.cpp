class Solution {
public:
 bool findd(int n,unordered_map<int,int> free){
        int cnt=0;
         while(n>0){
            if(free[n%10]<=0){
                break;
            }
                cnt++;
                free[n%10]--;
                n=n/10;
         }
         return cnt==3;
 }
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> free;
        for(int i=0;i<digits.size();i++){
            free[digits[i]]++;
        }
        vector<int> res;
        for(int i=100;i<=999;i=i+2){
            if(findd(i,free)){
                res.push_back(i);
            }
        }
        set<int>st;
            st.insert(begin(res),end(res));
        int ans=st.size();
        return ans;
    }
};