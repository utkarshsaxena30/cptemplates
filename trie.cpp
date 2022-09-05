struct TrieNode {
    vector<TrieNode*> children;
    bool is_terminal;

    TrieNode() {
        children = vector<TrieNode*>(26, NULL);
        is_terminal = false;
    }
};

class Trie {
    TrieNode *root;

    void clear(TrieNode *root) {
        for(int i = 0; i < 26; i++) if(root->children[i]) clear(root->children[i]);
        delete(root);
    }

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }

    void insert(string word) {
        TrieNode *node = root;
        for(auto ch: word) {
            if(!node->children[ch - 'a']) node->children[ch - 'a'] = new TrieNode();
            node = node->children[ch - 'a'];
        }
        node->is_terminal = true;
    }

    bool search(string word) {
        TrieNode *node = root;
        for(auto ch: word) {
            if(!node->children[ch - 'a']) return false;
            node = node->children[ch - 'a'];
        }

        return node->is_terminal;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(auto ch: prefix) {
            if(!node->children[ch - 'a']) return false;
            node = node->children[ch - 'a'];
        }
        return true;
    }
};
