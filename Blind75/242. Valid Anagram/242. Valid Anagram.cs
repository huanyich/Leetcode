/* public class Solution {
    public void sort(ref string s){
        char[] array = s.ToCharArray();
        Array.Sort(array);
        s = new String(array);
    }
    
    public bool IsAnagram(string s, string t) {
        sort(ref s);
        sort(ref t);

        return s==t?true:false;
    }
} */

public class Solution {

    
    public bool IsAnagram(string s, string t) {
        HashTable st = new HashTable();
        HashTable tt = new HashTable();

        foreach(char c in s){
            st.Add(c,)
        }
    }
}
