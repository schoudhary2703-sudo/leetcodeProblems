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
    void makeArray(TreeNode *root, vector<TreeNode*> &arr){
        if(root==nullptr)return ;
        makeArray(root->left,arr);
        arr.push_back(root);
        makeArray(root->right,arr);
    }
    TreeNode* balance(vector<TreeNode*> &arr, int l , int r){
        if (l > r) return nullptr;
        int mid = l+(r-l)/2;
        arr[mid]->left=balance(arr,l,mid-1);
        arr[mid]->right=balance(arr,mid+1,r);
        return arr[mid];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        makeArray(root, arr);
        int n = arr.size();
        return balance(arr,0,n-1);
    }
};