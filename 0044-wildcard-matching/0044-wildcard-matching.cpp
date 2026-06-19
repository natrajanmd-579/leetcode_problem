class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> dp(n+1, false);

        dp[0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*')
                dp[j] = dp[j-1];
        }

        for (int i = 1; i <= m; i++) {
            vector<bool> newDp(n+1, false);

            for (int j = 1; j <= n; j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    newDp[j] = dp[j-1];
                }
                else if (p[j-1] == '*') {
                    newDp[j] = dp[j] || newDp[j-1];
                }
            }

            dp = newDp;
        }

        return dp[n];
    }
};