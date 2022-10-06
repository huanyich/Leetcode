public class Solution {
    public void sort(ref string s){
        char[] array = s.ToCharArray();
        Array.Sort(array);
        s = new String(array);
    }
    
    public bool IsAnagram(string s, string t) {
        sort(ref s); // in C# dont have a build in func for sorting an array
        sort(ref t); // therefore write one

        return s==t?true:false;
    }
}
