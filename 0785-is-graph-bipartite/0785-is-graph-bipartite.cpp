class Solution {
private:
    bool bfs(int  i,vector<vector<int>> &graph, vector<int> &colors){
        queue<int> q;
        q.push(i);
        colors[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int u: graph[node]){
                if(colors[u]==-1){
                    colors[u]=1-colors[node];
                    q.push(u);
                }else if(colors[u]==colors[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> colors(n,-1);
        for(int i =0;i<n;i++){
            if(colors[i]==-1){
                if(!bfs(i,graph,colors)){
                return false;
            }
            }
        }
        return true;
    }
};