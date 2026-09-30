class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
         vector<int> ans(seq.size());
         int dep=0;
         for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                ++dep;
                ans[i]=dep%2;
            }
            else{
                ans[i]=dep%2;
                --dep;
            }
         }
         return ans;
    }
};