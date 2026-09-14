class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(const auto& pair: prerequisites){
            int pre=pair[1];
            int course=pair[0];
            adj[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        int visitedCourse=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            res.push_back(x);
            visitedCourse++;

            for(int u:adj[x]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
            }
        }
        if(visitedCourse==numCourses){
            return res;
        }
        return {};
    }
};