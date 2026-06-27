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
    int countNodes(TreeNode* root) {
        int leftlvl=leftdepth(root);
        int rightlvl=rightdepth(root);
        if(leftlvl==rightlvl)return (1<<rightlvl)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
private:
        int leftdepth(TreeNode* root){
            int depth=0;
            while(root!=nullptr){
                depth++;
                root=root->left;
            }
            return depth;
        }
        int rightdepth(TreeNode* root){
            int depth=0;
            while(root!=nullptr){
                depth++;
                root=root->right;
            }
            return depth;
        }
};