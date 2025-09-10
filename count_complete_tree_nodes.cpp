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
    void search(TreeNode* node, int& cnt){
        if(!node)
            return;
        cnt++;
        search(node->left, cnt);
        search(node->right, cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;

        search(root, cnt);

        return cnt;
    }
};
