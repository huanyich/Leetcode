public class Solution {
    IList<IList<int>> res = new List<IList<int>>();
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        //backtracking
        List<int> tmp = new List<int>();
        backtracking(candidates, target, ref tmp, 0, 0);
        return res;
    }

    void backtracking(int[] candidates, int target, ref List<int> tmp, int index, int sum){
        //basecase
        if(sum==target){
            res.Add(tmp.ToList());
            return;
        }
        if(sum>target) return;

        for(int i=index; i<candidates.Length; i++){
            tmp.Add(candidates[i]);
            sum+=candidates[i];
            backtracking(candidates, target, ref tmp, i, sum);
            sum-=candidates[i];
            tmp.RemoveAt(tmp.Count-1);
        }
    }
}
