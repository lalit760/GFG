class Solution {
  public:
    vector<vector<int>> dp;
    int helper(int w, vector<int> &val, vector<int> &wt, int idx, int n){
        if(idx==n) return 0;
        
        if(dp[idx][w] != -1) return dp[idx][w];
        
        
        
        if(w-wt[idx] < 0){ //i can't take i have to leave
            return dp[idx][w] = helper(w, val, wt, idx+1, n);
        }
        
        int take = val[idx] + helper(w-wt[idx], val, wt, idx+1, n);
        int leave = helper(w, val, wt, idx+1, n);
        
        return dp[idx][w] = max(take,leave);
    }
    
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        dp.resize(n, vector<int>(w+1, -1));
        
        return helper(w, val, wt, 0,n);
    }
};