class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;

        queue<Node*> q;

        q.push(root);

        while(!q.empty()){
            int len = q.size();
            Node* prev = nullptr;

            for(int i = 0; i < len; i++){
                Node* curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
                
                if(prev)
                    prev->next = curr;

                prev = curr;
            }
        }

        return root;
    }
};
