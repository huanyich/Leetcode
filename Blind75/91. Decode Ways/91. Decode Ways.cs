public class Solution {
    public Dictionary<string, int> number = new Dictionary<string, int>();
    public Dictionary<string, int> memo = new Dictionary<string, int>();
    public int NumDecodings(string s) {
        for(int i=1; i<=26; i++){
            number.Add(i.ToString(), 1);
        }
       return helper(s); 
    }

    public int helper(string s){
        //base case
        if(s=="") return 1;
        if(s[0]=='0') return 0;
        if(memo.ContainsKey(s)) return memo[s];
        int n = s.Length;
        int sum = 0;
        for(int i=0; i<n; i++){
            if(number.ContainsKey(s.Substring(0,i+1))){
                sum+= helper(s.Substring(i+1));
            }
        }

        return memo[s] = sum;



    }  
}
