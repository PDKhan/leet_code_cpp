class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& pos, vector<int>& inorder, int start, int end, unordered_map<int, int>& map) {
        if(start >= end)
            return nullptr;

        int val = preorder[pos++];
        TreeNode* root = new TreeNode(val);

        root->left = build(preorder, pos, inorder, start, map[val], map);
        root->right = build(preorder, pos, inorder, map[val] + 1, end, map);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        unordered_map<int, int> map;

        for(int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;

        return build(preorder, pos, inorder, 0, inorder.size(), map);
    }
};
