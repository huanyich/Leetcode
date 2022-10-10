public class Solution {
    public int MaxProfit(int[] prices) {
        int n = prices.Length;
        int curr_min = prices[0];
        int res = 0;
        foreach(int i in prices){
            curr_min = Math.Min(curr_min, i);
            res = Math.Max(res, i - curr_min);
        }

        return res;
    }
}
