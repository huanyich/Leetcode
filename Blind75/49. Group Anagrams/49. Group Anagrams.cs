public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        Dictionary<string, IList<string>> dic= new Dictionary<string, IList<string>>();

        for(int i =0; i<strs.Length; i++){
            char[] arr = strs[i].ToCharArray();
            Array.Sort(arr);
            string sorted = new string(arr);

            if(dic.ContainsKey(sorted)){
                dic[sorted].Add(strs[i]);
            }else{
                dic.Add(sorted, new List<string>(){strs[i]});
            }
        }

        var result = dic.Values.ToList();
        return result;
        
    }
}
