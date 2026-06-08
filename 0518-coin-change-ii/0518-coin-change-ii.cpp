class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i] <= LLONG_MAX - dp[i - coin]) {
                    dp[i] += dp[i - coin];
                }
            }
        }

        return (int)dp[amount];
    }
};