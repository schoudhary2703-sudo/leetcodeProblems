class Codec {
public:
// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            if(temp == nullptr)s+="#,";
            else{
                s+=to_string(temp->val)+',';
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;//"5,6,8,#,#,6,#"
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //recieved string will be like "5,6,8,#,#,6,#"
        if(data.empty())return nullptr;
        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode *temp =q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
                TreeNode* leftNode = new TreeNode(stoi(str));
                temp->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str!="#"){
                TreeNode *rightNode= new TreeNode (stoi(str));
                temp->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));