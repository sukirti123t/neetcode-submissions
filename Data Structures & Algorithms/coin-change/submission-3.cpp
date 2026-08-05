class Solution {
public:
vector<int> dp;

int dfs(int rem,vector<int>& coins){
    if(rem==0)
    return 0;
    if(rem<0)
    return INT_MAX;
    if(dp[rem]!=-1)
    return dp[rem];
     int ans=INT_MAX;

     for(int coin:coins){
      int result=  dfs(rem-coin,coins);
      if(result != INT_MAX){
         ans=min(ans,result+1);}

     }

     dp[rem]=ans;
     return dp[rem];


}



    int coinChange(vector<int>& coins, int amount) {
         dp.resize(amount + 1, -1);

        int ans = dfs(amount, coins);

        if (ans == INT_MAX)
            return -1;

        return ans;

        
    }
};
