class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        int depth = 0;

        q.push(root);

        while(!q.empty()){
            int len = q.size();
            vector<int> vt;

            for(int i = 0; i < len; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

                vt.push_back(curr->val);
            }

            if(depth % 2)
                reverse(vt.begin(), vt.end());

            depth++;
            result.push_back(vt);
        }

        return result;
    }
};