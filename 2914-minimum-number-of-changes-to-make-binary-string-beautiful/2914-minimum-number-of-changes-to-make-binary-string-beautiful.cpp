class Solution {
public:
    int minChanges(string s) {
           int n=s.length();
           char ch=s[0];
           int cnt=0;
           int change=0;
           for(int i=0;i<n;i++){
              if(s[i]==ch){
                cnt++;
                continue;
              }
              if(cnt%2==0){
                cnt=1;
              } else{
                change++;
                cnt=0;
              }
              ch=s[i];
           }
           return change;
    }
};