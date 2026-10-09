class Solution {
public:
    int minInsertions(string s) {
       int cnt=0,res=0,i=0;
       while(i<s.length()){
         if(s[i]=='('){
            cnt++;
            i++;
         }
         else{
            if(cnt>0){
                cnt--;
            }
            else{
                res+=1;
            }
            if(s[i+1]==')'){
                i+=2;
            }
            else{
                res+=1;
                i++;
            }
       }
    }
       return cnt*2+res;
    }
};