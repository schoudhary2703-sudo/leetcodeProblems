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
public:
    TreeNode* helper(vector<int>& nums,int left ,int right){
        if(left>right){
            return nullptr;
        }
        int x = left+(right-left)/2;
        TreeNode *root=new TreeNode(nums[x]);
        root->left=helper(nums,left,x-1);
        root->right=helper(nums ,x+1,right);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);

    }
};