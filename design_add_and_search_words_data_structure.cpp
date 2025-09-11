class Node{
public:
    bool isEnd;
    Node* children[26];
    Node(){
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
    ~Node(){
        for(int i = 0; i < 26; i++){
            if(children[i])
                delete children[i];
        }
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node;
    }
    ~WordDictionary(){
        delete root;
    }
    
    void addWord(string word) {
        Node* node = root;

        for(char ch : word){
            int idx = ch - 'a';

            if(!node->children[idx])
                node->children[idx] = new Node;
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool dfs(int pos, Node* node, string& word){
        if(pos == word.length())
            return node->isEnd;

        char ch = word[pos];
        int idx = ch - 'a';

        if(ch != '.'){
            if(!node->children[idx])
                return false;
            return dfs(pos + 1, node->children[idx], word);
        }

        for(int i = 0; i < 26; i++){
            if(node->children[i])
                if(dfs(pos + 1, node->children[i], word))
                    return true;
        }

        return false;
    }

    bool search(string word) {
        return dfs(0, root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
