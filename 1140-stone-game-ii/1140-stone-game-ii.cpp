class Solution {
public:

    int solve(int i, int M, vector<int>& piles, vector<vector<int>>& dp) {

        int n = piles.size();

        if (i >= n) {
            return 0;
        }

        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int total = 0;
        int best = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            total += piles[i + X - 1];

            int opponent = solve(i + X, max(M, X), piles, dp);

            int current = total + 
                          (accumulate(piles.begin() + i + X,
                                      piles.end(), 0) - opponent);

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles, dp);
    }
};