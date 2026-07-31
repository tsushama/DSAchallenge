class Solution {
public:
    int minimumPushes(string word) {
        vector<int>fre(26,0);
        for(char ch:word){
            fre[ch-'a']++;
        }
        sort(fre.begin(),fre.end(),greater<int>());
        int ans=0;
        for(int i=0;i<26;i++){
            if(fre[i]==0) break;
            ans+=fre[i]*((i/8)+1);
        }
        return ans;
    }
};