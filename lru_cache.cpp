class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int _key, int _value){
        key = _key;
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    int size;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;

    LRUCache(int _capacity) {
        size = 0;
        capacity = _capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void move_to_head(Node* node){
        if(node->prev)
            node->prev->next = node->next;
        if(node->next)
            node->next->prev = node->prev;
        
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
 
    int get(int key) {
        if(map.count(key) == 0)
            return -1;

        Node* node = map[key];

        move_to_head(node);

        return node->value;
    }
    
    void remove_tail(){
        Node* node = tail->prev;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        map.erase(node->key);
        delete node;
    }

    void put(int key, int value) {
        if(map.count(key) == 0){
            Node* node = new Node(key, value);

            map[key] = node;

            move_to_head(node);

            if(size == capacity)
                remove_tail();
            else
                size++;
        }else{
            Node* node = map[key];

            node->value = value;
            move_to_head(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */