class Solution {
  public:
    vector<vector<int>>dp;
    int helper(vector<int>& val,vector<int>& wt,int cap,int i,int w){
        if(i==val.size()) return 0;
        // if(wt[i] > cap) return 0;
        if(dp[i][w] != -1) return dp[i][w];
        
        if(w+wt[i] > cap){
            return dp[i][w]= helper(val,wt,cap,i+1,w);
        }
        
        else{
            int take = val[i] + helper(val,wt,cap,i,w+wt[i]);
            int leave = helper(val,wt,cap,i+1,w);
            
            return dp[i][w] = max(take,leave);
        }
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        // return finalAns;
        
        dp.resize(n,vector<int>(capacity+1,-1));
        int finalAns = helper(val, wt, capacity,0,0);
        return finalAns;
    }
};