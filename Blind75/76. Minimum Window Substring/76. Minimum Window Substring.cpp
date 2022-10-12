public class Solution {
    public string MinWindow(string s, string t) {
        Dictionary<char, int> need = new Dictionary<char,int>();
        Dictionary<char, int> window = new Dictionary<char, int>();

        //first build the t_map
        foreach(char c in t){
            if(need.ContainsKey(c)){
                need[c]++;
            }else{
                need.Add(c,1);
            }
        }

        int start = 0;
        int left = 0;
        int res = Int32.MaxValue;
        int count = 0;
        for(int i=0; i<s.Length; i++){
            char curr = s[i];
            if(need.ContainsKey(curr) && window[curr] < need[curr]){
                count++;
            }
            window[curr]++;
            while(count==t.Length){
                if(res> i-left+1){
                    res = i-left+1;
                    start = left;
                }else{
                    
                }
            }

        }




    }
