class Solution {
    public Integer[] dp;
    public int maximizeTheProfit(int n, List<List<Integer>> ls) {
        dp = new Integer[ls.size() + 1];
        Collections.sort(ls, (l , r) -> (l.get(0) - r.get(0)));
        return solve(ls, 0);
    }
    
    public int solve(List<List<Integer>> ls, int i){
        if(i >= ls.size()){
            return 0;
        }
        if(dp[i] != null) return dp[i];
        int id = ceil(ls, ls.get(i).get(1));
        int take = ls.get(i).get(2) + solve(ls, id);
        int not = solve(ls, i + 1);
        return dp[i] = Math.max(take, not);
    }
    public int ceil(List<List<Integer>> ls, int x){
        int ans = ls.size();
        int left = 0;
        int right = ls.size()-1;
        while(left <= right){
            int mid = left + ( right - left)/2;
            if(ls.get(mid).get(0) > x){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
}