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
    void makeArray(TreeNode *root,vector<int> &arr){
        if(root==nullptr){
            return;
        }
        makeArray(root->left,arr);
        arr.push_back(root->val);
        makeArray(root->right,arr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sortedArray;
        makeArray(root,sortedArray);
        return sortedArray[k-1];
    }
};