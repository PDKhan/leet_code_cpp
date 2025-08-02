class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> q;

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

            result.push_back(vt);
        }

        return result;
    }
};