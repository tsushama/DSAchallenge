class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dis(m,vector<vector<int>>(n,vector<int>(1024,0)));
        queue<pair<pair<int,int>,int>>pq;
        pq.push({{0,0},grid[0][0]});
        dis[0][0][grid[0][0]]=1;
        int dx[2]={0,1};
        int dy[2]={1,0};
        while(!pq.empty()){
            int x=pq.front().second;
            int i=pq.front().first.first;
            int j=pq.front().first.second;
            pq.pop();
            for(int k=0;k<2;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int na=x^grid[nx][ny];
                    if(dis[nx][ny][na]==0){
                        dis[nx][ny][na]=1;
                        pq.push({{nx,ny},na});
                    }
                }
            }
        }
        for(int i=0;i<1024;i++){
            if(dis[m-1][n-1][i]!=0)return i;
        }
        return -1;
    }
};