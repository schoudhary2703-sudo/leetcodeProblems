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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal=p->val;
        int rootVal=root->val;
        int qVal=q->val;
        TreeNode* ans=nullptr;
        if(rootVal>qVal && rootVal>pVal){
            ans=lowestCommonAncestor(root->left,p,q);

        }else if(rootVal<qVal && rootVal<pVal){
            ans=lowestCommonAncestor(root->right,p,q);
        }
        else{
            ans=root;
        }
        return ans;
    }
};