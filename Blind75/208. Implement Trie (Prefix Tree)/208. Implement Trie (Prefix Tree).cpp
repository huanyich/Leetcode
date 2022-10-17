class Trie {
public:
    Trie* children[26];
    bool isEnd;
    //Constructor
    Trie() {
        for(int i=0; i<26; i++){
            children[i] = NULL;
            isEnd = false;
        }
    }
    void insert(string word) {
        Trie* node = this;
        for(char c:word){
            if(node->children[c-'a']==NULL){
                node->children[c-'a'] = new Trie();
            }
            node = node->children[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c:word){
            if(node->children[c-'a']==NULL) return false;
            node = node->children[c-'a'];
        }
        return node->isEnd?true:false;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c:prefix){
            if(node->children[c-'a']==NULL) return false;
            node = node->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
