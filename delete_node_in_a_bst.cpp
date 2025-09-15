class Solution {
public:
    TreeNode* insert_node(TreeNode* right, TreeNode* left){
        if(!right)
            return left;
        
        if(!left)
            return right;

        right->left = insert_node(right->left, left);
        return right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;

        TreeNode* prev = nullptr;
        TreeNode* node = root;

        while(node && node->val != key){
            prev = node;

            if(node->val > key)
                node = node->left;
            else
                node = node->right;
        }

        if(!node)
            return root;

        if(prev == nullptr){
            root = insert_node(node->right, node->left);
        }else if(prev->val > node->val){
            prev->left = insert_node(node->right, node->left);
        }else{
            prev->right = insert_node(node->right, node->left);
        }

        delete node;

        return root;
    }
};