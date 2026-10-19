class DisjointSet { 
public:
    vector<int> rank, parent;

    int findUparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUparent(parent[node]);
    }
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    bool find(int u, int v) {
        int ult_u=findUparent(u);
        int ult_v=findUparent(v);
        if(ult_u==ult_v)return true;
        return false;  
    }
    void unionByRank(int u, int v) {
        int ult_u=findUparent(u);
        int ult_v=findUparent(v);
        if(ult_u==ult_v)return;
        else if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;
        }
        else{
            parent[ult_u]=ult_v;
            rank[ult_v]++;
        }
    }
    void unionBySize(int u, int v) {
        int ult_u=findUparent(u);
        int ult_v=findUparent(v);
        if(ult_u==ult_v)return;
        else if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
            rank[ult_v]+=rank[ult_u];
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;
            rank[ult_u]+=rank[ult_v];
        }
        else{
            parent[ult_u]=ult_v;
            rank[ult_v]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
         int n=accounts.size();
         DisjointSet ds(n);
         unordered_map<string,int> map;
         for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(map.find(mail)==map.end()){
                    map[mail]=i;
                }
                else{
                    ds.unionBySize(i,map[mail]);
                }
            }
         }

         vector<string>mergestring[n];
         for(auto it:map){
            string mail=it.first;
            int node=ds.findUparent(it.second);
            mergestring[node].push_back(mail);
         }
         vector<vector<string>> ans;
         for(int i=0;i<n;i++){
            if(mergestring[i].size()==0) continue;
            sort(mergestring[i].begin(),mergestring[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergestring[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
         }
         return ans;
    }
};