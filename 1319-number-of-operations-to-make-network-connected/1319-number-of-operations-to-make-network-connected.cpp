class DisjointSet {
private:
    //vector<int> rank, parent;
    /*int findUparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUparent(parent[node]);
    }*/
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntext=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUparent(u)==ds.findUparent(v)){
                cntext++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cntc++;
            }
        }
        int ans=cntc-1;
        if(cntext>=ans) return ans;
        return -1;
    }
};