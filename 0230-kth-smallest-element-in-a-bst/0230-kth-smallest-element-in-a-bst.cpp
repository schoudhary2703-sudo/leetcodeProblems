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
    bool makeArray(TreeNode *root,int k,int &count,int &ans){
        if(root==nullptr){
            return false;
        }
        if(makeArray(root->left,k,count,ans)){
            return true;
        }
        count++;
        if(count==k){
            ans=root->val;
            return true;
        }
        if(makeArray(root->right,k,count,ans)){
            return true;
        }
        return false;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=0;
        makeArray(root,k,count,ans);
        return ans;
    }
};