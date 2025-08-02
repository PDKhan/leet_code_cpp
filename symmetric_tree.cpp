class Solution {
public:
    bool check(TreeNode* left, TreeNode* right){
        if(left && right){
            if(left->val != right->val)
                return false;
            
            return check(left->left, right->right) && check(left->right, right->left);
        }else if(left)
            return false;
        else if(right)
            return false;
        else
            return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return check(root->left, root->right);
    }
};