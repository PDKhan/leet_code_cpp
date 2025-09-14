class Node {
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

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node;
    }
    ~Trie(){
        delete root;
    }
    void insert(Node* node, string word){
        for(char ch : word){
            int idx = ch - 'a';
            if(!node->children[idx])
                node->children[idx] = new Node;
            node = node->children[idx];
        }

        node->isEnd = true;
    }
};

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, Node* node, string& buf, vector<string>& result){
        if(node->isEnd){
            result.push_back(buf);
            node->isEnd = false;
        }

        if(r < 0 || r >= board.size() || c < 0 || c >= board[r].size() || board[r][c] == '#')
            return;

        char ch = board[r][c];
        int idx = ch - 'a';

        if(!node->children[idx])
            return;
        
        board[r][c] = '#';
        buf.push_back(ch);

        dfs(r - 1, c, board, node->children[idx], buf, result);
        dfs(r + 1, c, board, node->children[idx], buf, result);
        dfs(r, c - 1, board, node->children[idx], buf, result);
        dfs(r, c + 1, board, node->children[idx], buf, result);

        board[r][c] = ch;
        buf.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(string str : words){
            t.insert(t.root, str);
        }

        string buf;
        vector<string> result;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                dfs(i, j, board, t.root, buf, result);
            }
        }

        return result;
    }
};
