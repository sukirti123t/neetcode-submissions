class Solution {
public:vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {


dp.resize(cost.size(), -1);
return min(dfs(0, cost), dfs(1, cost));}
    

int dfs(int i,vector<int>& cost){
    if( i >= cost.size())
    return 0;
if (dp[i]!=-1)
return dp[i];

dp[i]= cost[i]+min(dfs(i+1,cost),dfs(i+2,cost)); 
return dp[i];
    
}
        
     
    };
