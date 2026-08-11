class Solution {
public:
   void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
             int row=q.front().first;
             int col=q.front().second;
             q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    bfs(nrow,ncol,vis,grid);
                }
            }
        }
   }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};