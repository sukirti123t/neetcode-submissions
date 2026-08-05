class Solution {
public:

vector<vector<int>> dp;
int target ;

bool dfs(int i ,int sum,vector<int>& nums){
    if(sum==target)
    return true;
    if(sum> target)
    return false;
    if(i==nums.size())
    return false;
    if(dp[i][sum] != -1)
    return dp[i][sum];
    bool take= dfs(i+1,sum+nums[i],nums);
    bool skip= dfs(i+1 ,sum,nums);

    int ans=take||skip;
    dp[i][sum]= ans;
    return dp[i][sum];

}


    bool canPartition(vector<int>& nums) {

int total =0;
for(int num: nums){
    total +=num;
}
if(total%2 != 0)
return false;

 target =total /2;
 dp.resize(nums.size(), vector<int>(target + 1, -1));

return dfs(0, 0, nums);

    }
};
