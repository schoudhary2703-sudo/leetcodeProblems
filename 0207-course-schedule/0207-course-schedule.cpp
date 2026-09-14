class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(const auto& pair: prerequisites){
            int pre=pair[0];
            int course=pair[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int visitedCourse=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            visitedCourse++;
            for(int u:adj[x]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
            }
        }
        return visitedCourse==numCourses;
    }
};