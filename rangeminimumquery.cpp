int LOG = log2(n) + 1;
vector<vector<int>> dp(n, vector<int>(LOG));

// BUILDING THE DP
for (int j = 1; j < LOG; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
        if (j == 1)
            dp[i][j] = min(nums[i], nums[i + 1]);
        else
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
}

// ANSWERING QUERY [st, en]
int rmq(int st, int en) {
    if (st == en)
        return nums[st];
    else {
        int x = log2(en - st + 1);
        int ans = min(dp[st][x], dp[en - (1 << x) + 1][x]);
        return ans;
    }
}