class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<int> dist(n+1,1e9);
         dist[k]=0;
         for(int i=1;i<=n-1;i++){
             for(auto it:times){
                 if(dist[it[0]]!=1e9 && dist[it[0]]+it[2]<dist[it[1]]){
                    dist[it[1]]=dist[it[0]]+it[2];
                 }
             }
         }
         int res=0;
         for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            res=max(res,dist[i]);
         }
         return res;
    }
};