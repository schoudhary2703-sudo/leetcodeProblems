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
    TreeNode* solve (vector<int> &pre,vector<int>&in,int &index,int start,int end,int n,map<int,int> &mp){
        if(index>=n || start>end){
            return NULL;
        }
        int element=pre[index++];
        TreeNode* root=new TreeNode (element);
        int pos=mp[element];
        root->left=solve(pre,in,index,start,pos-1,n,mp);
        root->right=solve(pre,in,index,pos+1,end,n,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int index=0;
        TreeNode* ans=solve(preorder,inorder,index,0,n-1,n,mp);
        return ans;
    }
};