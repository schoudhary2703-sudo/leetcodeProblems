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
// private: 
//     void makeArray(TreeNode* root,vector<TreeNode*> &arr){
//         if(root==nullptr)return ;
//         arr.push_back(root);
//         makeArray(root->left,arr);
        
//         makeArray(root->right,arr);
//     }
public:
    void flatten(TreeNode* root) {
        // vector<TreeNode* > arr;
        // makeArray(root,arr);
        // if (arr.empty()) return;
        // for(int i =0;i<arr.size()-1;i++){
        //     arr[i]->left=nullptr;
        //     arr[i]->right=arr[i+1];
        // }
        // arr.back()->left=nullptr;
        // arr.back()->right=nullptr;
        //optimal sol
        TreeNode* curr=root;
        while(curr != nullptr){
            while(curr->left != nullptr){
                TreeNode* temp=curr->left;
                while(temp->right!=nullptr){
                    temp=temp->right;
                }
                temp->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};