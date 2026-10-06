class Solution {
public:
    int minAddToMakeValid(string s) {
        int add=0,open=0;
         for(char c:s){
            if(c=='('){
                open++;
            }
            else{
                if(open>0){
                   open--;
                }
                else{
                    add++;
                }
            }
         }
         return open+add;;
    }
};