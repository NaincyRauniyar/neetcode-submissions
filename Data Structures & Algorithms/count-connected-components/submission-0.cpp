class Solution {
public:
void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
    vis[node] = true;
    for(auto &nei:adj[node]){
        if(!vis[nei])
        dfs(nei,adj,vis);
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
         vector<bool> vis(n, false);
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
