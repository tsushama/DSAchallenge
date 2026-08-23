class Solution {
public:
    bool sumGame(string num) {
         int n=num.length();
         int rightsum=0,leftsum=0;
         int leftq=0,rightq=0;
         for(int i=0;i<n/2;i++){
            if(num[i]=='?') leftq++;
            else leftsum+=num[i]-'0';
         }
         for(int i=n/2;i<n;i++){
            if(num[i]=='?') rightq++;
            else rightsum+=num[i]-'0';
         }
         return (rightsum-leftsum)*2 != (leftq-rightq)*9;
    }
};