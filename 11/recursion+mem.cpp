class Solution {
public:
    vector<vector<int>> dp;
    void build_dp(int amount, vector<int>& coins, int n)
    {
        // cout << n << " " << amount << endl;
        if(n == 0)
        {
            dp[n][amount] = 0;
            return;
        }
        
        if(amount == 0)
        {
            dp[n][amount] = 1;
            return;
        }

        if(dp[n][amount] != -1)
        {
            // cout << "!\n";
            return;
        }

        if(coins[n-1] > amount)
        {
            build_dp(amount, coins, n-1);
            dp[n][amount] = dp[n-1][amount];
            return;
        }

        
        build_dp(amount-coins[n-1], coins, n);
        build_dp(amount, coins, n-1);
        dp[n][amount] = dp[n-1][amount] + dp[n][amount - coins[n-1]];
        return;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1, vector<int>(amount+1, -1));
        build_dp(amount, coins, n);
        return dp[n][amount];
    }
};