class Solution {
public:
    int maxDepth(string s) {
         int curr=0,sol=0;
         for(char c:s){
            if(c=='('){
                curr++;
                sol=max(sol,curr);
            }
            else if(c==')'){
                curr--;
            }
         }
         return sol;
    }
};