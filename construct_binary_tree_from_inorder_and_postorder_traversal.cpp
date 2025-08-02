class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& pos, int start, int end, unordered_map<int, int>& map) {
        if(start >= end)
            return nullptr;
        
        int val = postorder[pos--];
        TreeNode* root = new TreeNode(val);

        root->right = build(inorder, postorder, pos, map[val] + 1, end, map);
        root->left = build(inorder, postorder, pos, start, map[val], map);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size() - 1;
        unordered_map<int, int> map;

        for(int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        
        return build(inorder, postorder, pos, 0, inorder.size(), map);
    }
};
