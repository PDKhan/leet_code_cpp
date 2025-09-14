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
    void search(TreeNode* node, bool isLeft, int& result){
        if(!node)
            return;

        search(node->left, true, result);

        if(!node->left && !node->right && isLeft){
            result += node->val;
            return;
        }

        search(node->right, false, result);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;

        search(root, false, result);
        return result;
    }
};
