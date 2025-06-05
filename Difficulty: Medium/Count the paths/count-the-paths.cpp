class Solution {
  public:
   int dfs(int curr, int dest, vector<vector <int>>& adj, vector <int>& vis){
        if(curr == dest) return 1;
        if(vis[curr] != -1) return vis[curr];
        
        int cnt = 0;
        for(int nbr: adj[curr]){
            cnt += dfs(nbr, dest, adj, vis);
        }
        
        return vis[curr] = cnt;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector <int>> adj(V);
        vector <int> vis(V, -1);
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        return dfs(src, dest, adj, vis);
    }
};