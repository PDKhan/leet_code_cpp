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
    int maxLevelSum(TreeNode* root) {
        if(!root)
            return 0;

        queue<TreeNode*> q;
        int depth = 1;
        int result = 0;
        int max_val = INT_MIN;
        q.push(root);

        while(!q.empty()){
            int sum = 0;
            int len = q.size();

            for(int i = 0; i < len; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

                sum += curr->val;   
            }

            if(max_val < sum){
                max_val = sum;
                result = depth;
            }

            depth++;
        }

        return result;
    }
};
