class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        
        struct TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);

        return root;  
    }
};
