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
    TreeNode* build(vector<int> & preorder, int mini,int maxi , int &i){
        if(i>=preorder.size()) return nullptr;
        if(preorder[i]<mini || preorder[i] > maxi){
            return nullptr;
        }
        TreeNode* root= new TreeNode(preorder[i++]);
        root->left=build(preorder,mini,root->val,i);
        root->right=build(preorder,root->val,maxi,i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int maxi=INT_MAX;
        int mini=INT_MIN;
        int i=0;
        return build(preorder,mini,maxi,i);
    }
};