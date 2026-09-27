class Solution {
public:
    string reverseParentheses(string s) {
         stack<int> skiplength;
         string result;
         for(char ch:s){
            if(ch=='('){
                skiplength.push(result.length());
            }
            else if(ch==')'){
                int l=skiplength.top();
                skiplength.pop();
                reverse(result.begin()+l,result.end());
            }
            else{
                result+=ch;
            }
         }
         return result;
    }
};