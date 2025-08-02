/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* new_head = nullptr;
        Node* tail;
        Node* search = head;

        while(search){
            if(new_head == nullptr){
                new_head = new Node(search->val);
                tail = new_head;
            }else{
                tail->next = new Node(search->val);
                tail = tail->next;
            }

            map[search] = tail;

            search = search->next;
        }

        search = head;
        tail = new_head;

        while(search){
            if(search->random)
                tail->random = map[search->random];
            else
                tail->random = nullptr;

            search = search->next;
            tail = tail->next;
        }

        return new_head;
    }
};
