class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(stop>k) continue;
            for(auto itr:adj[node]){
                int adjnode=itr.first;
                int edgewt=itr.second;
                if(dis+edgewt<dist[adjnode]){
                    dist[adjnode]=dis+edgewt;
                    q.push({stop+1,{adjnode,dis+edgewt}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};