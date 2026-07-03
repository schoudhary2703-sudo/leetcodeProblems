/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* mapping(TreeNode* root,int target,unordered_map<TreeNode*,TreeNode*> &mp){
        
        TreeNode* res=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * front=q.front();
            q.pop();
            if(front->val==target){
                res=front;
            }
            if(front->left){
                mp[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    void infectTree(TreeNode* node,int &ans,unordered_map<TreeNode*,TreeNode*> &mp){
        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*>q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=1;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=1;

                }
                if(mp[front] && !visited[mp[front]]){
                    q.push(mp[front]);
                    visited[mp[front]]=true;
                    flag=1;
                }
            
            }
            if(flag==1)ans++;
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;
        TreeNode* targetNode=mapping(root,start,mp);
        int ans=0;
        infectTree(targetNode,ans,mp);
        return ans;
    }
};