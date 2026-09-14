class Solution {
public:
    void dfs(int u,unordered_map<int, vector<int>> &adj , vector<bool> &visited){
        visited[u]=true;
        for(int v:adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                int u=i;
                int v=j;
                adj[u].push_back(v);
                adj[v].push_back(u);
                }
            }
        }
        int count = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                count++;
            }
            
        }
        return count;

    }
};