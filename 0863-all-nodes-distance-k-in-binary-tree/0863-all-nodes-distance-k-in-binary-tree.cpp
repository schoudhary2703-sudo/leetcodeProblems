/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void buildMap(TreeNode* node , unordered_map<TreeNode*,TreeNode*> &mp){
        if(node==nullptr)return;
        if(node->left!=nullptr){
            mp[node->left]=node;
            buildMap(node->left,mp);
        }
        if(node->right!=nullptr){
            mp[node->right]=node;
            buildMap(node->right,mp);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        buildMap(root,mp);
        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int current_distance=0;
        while(!q.empty()){
           if (current_distance == k) break;
           int size=q.size();
           for(int i=0;i<size;i++){
            TreeNode* front=q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                q.push(front->left);
                visited[front->left]=true;
            }
            if(front->right && !visited[front->right]){
                q.push(front->right);
                visited[front->right]=true;
            }
            if(mp[front]&& !visited[mp[front]]){
                q.push(mp[front]);
                visited[mp[front]]=true;
            }
           } 
           current_distance++;
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};