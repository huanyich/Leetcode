public class Solution {
    public bool IsValid(string s) {
        Stack<char> st = new Stack<char>();
        foreach(char c in s){
            if(c=='{' || c=='[' || c=='(') st.Push(c);
            else{
                if(st.Count==0) return false;
                else{
                    if(c=='}'){
                        if(st.Peek()=='{') st.Pop();
                        else return false;
                    }else if(c==']'){
                        if(st.Peek()=='[')st.Pop();
                        else return false;
                    }else{
                        if(st.Peek()=='(') st.Pop();
                        else return false;
                    }
                }
            }
        }

        return st.Count==0?true:false;
    }
}
