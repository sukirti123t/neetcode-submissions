class Solution {
public:
    vector<int> dp;

    int dfs(int i, int n) {

        if (i == n)
            return 1;

        if (i > n)
            return 0;

        // Already computed
        if (dp[i] != -1)
            return dp[i];

        int one = dfs(i + 1, n);
        int two = dfs(i + 2, n);

        dp[i] = one + two;

        return dp[i];
    }

    int climbStairs(int n) {

        dp.resize(n + 1, -1);

        return dfs(0, n);
    }
};