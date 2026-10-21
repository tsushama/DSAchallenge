class DisjointSet {
public:
     vector<int> rank, parent,size;

    int findUparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUparent(parent[node]);

    }
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,0);
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
        else if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];


        }
        else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }

    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        unordered_map<int,int>uniquenodes;
        DisjointSet ds(maxrow+maxcol+1);
        for(auto it: stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionBySize(noderow,nodecol);
            uniquenodes[noderow]=1;
            uniquenodes[nodecol]=1;
        }
        int cnt=0;
        for(auto it:uniquenodes){
            if(ds.findUparent(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};