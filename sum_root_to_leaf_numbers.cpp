class Solution {
public:
    void search(TreeNode* root, int sum,  int& result){
        if(!root)
            return;
        
        int val = root->val + (sum * 10);

        if(!root->left && !root->right){
            result += val;
            return;
        }

        search(root->left, val, result);
        search(root->right, val, result);
    }
    int sumNumbers(TreeNode* root) {
        int result = 0;

        search(root, 0, result);

        return result;
    }
};