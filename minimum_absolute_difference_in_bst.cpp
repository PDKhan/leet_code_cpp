class Solution {
public:
    void search(TreeNode* node, TreeNode* &prev, int &result){
        if(!node)
            return;
        
        search(node->left, prev, result);

        if(prev)
            result = fmin(abs(prev->val - node->val), result);

        prev = node;

        search(node->right, prev, result);
    }
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        TreeNode* prev = nullptr;

        if(!root)
            return result;
        
        search(root, prev, result);

        return result;
    }
};
