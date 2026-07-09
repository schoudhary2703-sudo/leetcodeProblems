class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> id(n, 0);
        int componentCount = 0;
        
        id[0] = 0; 
      
        for (int i = 1; i < n; i++) {
            
            if (nums[i] - nums[i - 1] > maxDiff) {
                componentCount++;
            }
            id[i] = componentCount;
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());
     
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            
            ans.push_back(id[u] == id[v]);
        }
        
        return ans;
    }
};