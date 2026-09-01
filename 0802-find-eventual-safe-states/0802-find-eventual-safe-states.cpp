class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int V=graph.size();
         vector<int> indegree(V,0);
         vector<int> adj[V];
         for(int i = 0; i < V; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
              adj[i].push_back(graph[i][j]);
               }
           }
         vector<int>adjRev[V];
         for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
         }
         queue<int>q;
         vector<int> safenodes;
         for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
         }
         while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
         }
         sort(safenodes.begin(),safenodes.end());
         return safenodes;

    }
};