class Solution {
public:
  long long bfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>& grid,long long sum){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
             int row=q.front().first;
             int col=q.front().second;
             sum+=grid[row][col];
             q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                !vis[nrow][ncol] && grid[nrow][ncol]>0){
                     q.push({nrow,ncol});
                     vis[nrow][ncol]=1;
                }
            }
        }
        return sum;
   }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int sum=0,cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    long long res=bfs(i,j,vis,grid,0LL);
                    if(res%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};