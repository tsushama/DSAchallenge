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
        size.resize(n+1,1);
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
    int largestIsland(vector<vector<int>>& grid) {
         int n=grid.size();
         DisjointSet ds(n*n);
         for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int ind=0;ind<4;ind++){
                      int newr=r+dr[ind];
                      int newc=c+dc[ind];
                    if(newr>=0 && newr<n && newc>=0 && newc<n){
                         if(grid[newr][newc]==1){
                            int nodeno=r*n+c;
                            int adjnodeno=newr*n+newc;
                            ds.unionBySize(nodeno,adjnodeno);
                          }
                    }
                }
            }
         }
          int mx=0;
         for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                 set<int> components;
                for(int ind=0;ind<4;ind++){
                      int newr=r+dr[ind];
                      int newc=c+dc[ind];
                    if(newr>=0 && newr<n && newc>=0 && newc<n){
                         if(grid[newr][newc]==1){
                           components.insert(ds.findUparent(newr*n+newc));
                          }
                    }
                }
               int size=0;
               for(auto it:components){
                 size+=ds.size[it];
               }
               mx=max(mx,size+1);
            }
         }
         for(int cell=0;cell<n*n;cell++){
            mx=max(mx,ds.size[ds.findUparent(cell)]);
         }
         return mx;
    }
};