class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> q;
        vector<int> result;

        q.push(root);

        while(!q.empty()){
            int len = q.size();
            int last;

            for(int i = 0; i < len ; i++){
                TreeNode* curr = q.front();
                q.pop();

                last = curr->val;

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            result.push_back(last);
        }

        return result;
    }
};
