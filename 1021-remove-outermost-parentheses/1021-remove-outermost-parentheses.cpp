class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
         int balance=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
             if(c=='('){
                if(balance>0){
                   ans=ans+c; 
                }
                balance++;
             }
             else{
                balance--;
                if(balance>0){
                    ans=ans+c;
                }
             }
        }
        return ans;
    }
};