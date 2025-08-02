class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
            return {};

        vector<double> result;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int len = q.size();
            double sum = 0;

            for(int i = 0; i < len; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
                sum += curr->val;
            }

            result.push_back(sum / len);
        }

        return result;
    }
};
