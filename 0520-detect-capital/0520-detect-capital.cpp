class Solution {
public:
    bool detectCapitalUse(string word) {
         int uppercase=0;
         for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                uppercase++;
            }
         }

         return uppercase==word.length()||
                uppercase==0 ||
                (uppercase==1 && word[0]-'a'<0);
    }
};