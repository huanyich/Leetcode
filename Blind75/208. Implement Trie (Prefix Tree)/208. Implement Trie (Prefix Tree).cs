public class Trie {
    Trie[] children = new Trie[26];
    bool isEnd;
    public Trie() {
        for(int i=0; i<26; i++){
            children[i] = null;
        }
        isEnd = false;
    }
    
    public void Insert(string word) {
        Trie node = this;
        foreach(char c in word){
            if(node.children[c-'a']==null){
                node.children[c-'a'] = new Trie();
            }
            node = node.children[c-'a'];
        }
        node.isEnd = true;
    }
    
    public bool Search(string word) {
        Trie node = this;
        foreach(char c in word){
            if(node.children[c-'a']==null){
                return false;
            }
            node = node.children[c-'a'];
        }

        return node.isEnd?true:false;
    }
    
    public bool StartsWith(string prefix) {
       Trie node = this;
        foreach(char c in prefix){
            if(node.children[c-'a']==null){
                return false;
            }
            node = node.children[c-'a'];
        }
        return true; 
    }
}


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.Insert(word);
 * bool param_2 = obj.Search(word);
 * bool param_3 = obj.StartsWith(prefix);
 */
