class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map){
        if(map.count(node))
            return map[node];
        
        Node* copy = new Node(node->val);

        map[node] = copy;

        for(int i = 0; i < node->neighbors.size(); i++){
            copy->neighbors.push_back(dfs(node->neighbors[i], map));
        }

        return copy;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;

        unordered_map<Node*, Node*> map;

        return dfs(node, map);
    }
};
