class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        TreeNode* right = curr->right;
        int val = curr->val;

        while(right){
            st.push(right);
            right = right->left;
        }
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
