class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int i, int end) {

        if(i > end)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int rob = nums[i] + solve(nums, i + 2, end);

        int skip = solve(nums, i + 1, end);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // Only one house
        if(n == 1)
            return nums[0];

        // Case 1: Exclude last house
        dp.assign(n, -1);
        int case1 = solve(nums, 0, n - 2);

        // Case 2: Exclude first house
        dp.assign(n, -1);
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};