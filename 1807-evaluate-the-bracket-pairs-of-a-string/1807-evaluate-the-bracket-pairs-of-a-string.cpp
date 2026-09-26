class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        string res="";
        for(auto pair:knowledge){
            mp[pair[0]]=pair[1];
        }
        int i=0;
        while(i<s.length()){
            if(s[i]=='('){
                i++;
                string temp="";
                while(s[i]!=')'){
                temp+=s[i];
                i++;
            }
            res+=mp.count(temp)?mp[temp]:"?";
        }
        else{
            res+=s[i];
        }
        i++;
     }
        return res;
    }
};