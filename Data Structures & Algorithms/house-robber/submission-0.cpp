class Solution {
public:
    vector<int> dp;

    int dfs(int i, vector<int>& nums) {

        // No houses left
        if (i >= nums.size())
            return 0;

        // Already computed
        if (dp[i] != -1)
            return dp[i];

        // Choice 1: Rob current house
        int rob = nums[i] + dfs(i + 2, nums);

        // Choice 2: Skip current house
        int skip = dfs(i + 1, nums);

        // Store the best choice
        dp[i] = max(rob, skip);

        return dp[i];
    }

    int rob(vector<int>& nums) {

        dp.resize(nums.size(), -1);

        return dfs(0, nums);
    }
};