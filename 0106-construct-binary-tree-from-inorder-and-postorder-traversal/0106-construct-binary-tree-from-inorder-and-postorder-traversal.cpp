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
    TreeNode* solve(vector<int> &post, int &index,int start,int end){
        if(start>end)return nullptr;
        int element = post[index--];
        TreeNode* root = new TreeNode(element);
        int pos=mp[element];
        root->right=solve(post,index,pos+1,end);
        root->left=solve(post,index,start,pos-1);
        return root;
    }
public:
    unordered_map<int , int> mp;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n =inorder.size();
        int index=n-1;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return solve(postorder,index,0,n-1);
    }
};