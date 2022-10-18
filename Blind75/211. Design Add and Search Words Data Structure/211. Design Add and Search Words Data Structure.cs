public class Trie{
    public Dictionary<char,Trie> child;
    public bool isEnd;
    public Trie(){
        child = new Dictionary<char,Trie>();
        isEnd = false;
    }
}
public class WordDictionary {
    Trie root = new Trie();
    public WordDictionary() {
    }
    
    public void AddWord(string word) {
        Trie node = root;
        foreach(char c in word){
            if(!node.child.ContainsKey(c)) node.child.Add(c, new Trie());
            node = node.child[c];
        }
        node.isEnd = true;
    }
    
    public bool Search(string word) {
        return SearchTrie(root,word,0);
    }


    public bool SearchTrie(Trie root, string word, int index){
        //base case
        if(index==word.Length) return root.isEnd;

        if(word[index]!='.'){
            char curr = word[index];

            if(!root.child.ContainsKey(curr)) return false;
            root = root.child[curr];
            return SearchTrie(root,word,index+1);
        }else{
            foreach(var node in root.child){
                if(SearchTrie(node.Value, word, index+1)) return true;
            }
            return false;
        }

    }

}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.AddWord(word);
 * bool param_2 = obj.Search(word);
 */
