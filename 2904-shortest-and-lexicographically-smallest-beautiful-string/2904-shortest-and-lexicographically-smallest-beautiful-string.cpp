class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        int i=0,j=0;
        int cnt=0;
        int ans=INT_MAX;
        string res="";
        while(j<n){
            if(s[j]=='1'){
                cnt++;
            }
            while(cnt>k){
                if(s[i]=='1'){
                    cnt--;
                }
                i++;
            }
           if(cnt==k){
                while(s[i]=='0'){
                    i++;
                }
               int len=j-i+1;
               string curr=s.substr(i,len);

               if(len<ans || (ans==len && curr<res)){
                ans=len;
                res=curr;
               }
           }
            j++;
        }
        return res;
    }
};