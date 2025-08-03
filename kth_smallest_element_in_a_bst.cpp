class Solution {
public:
    void search(TreeNode* root, int k, int& result, int& cnt){
        if(!root)
            return;
        
        if(cnt > k)
            return;
        
        search(root->left, k, result, cnt);

        cnt++;
        if(cnt == k)
            result = root->val;

        search(root->right, k, result, cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = INT_MIN;
        int cnt = 0;

        if(!root)
            return result;
        
        search(root, k, result, cnt);

        return result;
    }
};