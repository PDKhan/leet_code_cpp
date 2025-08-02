class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q){
            if(p->val != q->val)
                return false;
        }else if(p)
            return false;
        else if(q)
            return false;
        else
            return true;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
