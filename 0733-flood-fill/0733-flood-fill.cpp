class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initial=image[sr][sc];
        if(initial==color) return image;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            image[i][j]=color;
            for(int k=0;k<4;k++){
                int r=i+drow[k];
                int c=j+dcol[k];
                if(r>=0 && r<n && c>=0 && c<m && image[r][c]==initial){
                    q.push({r,c});
                }
            }
        }
        return image;

    }
};