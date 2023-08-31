class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 2, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<n+2; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(dp[max(0, j - ranges[j])] < INT_MAX && j + ranges[j] >= i)
                    dp[i] = min(dp[max(0, j - ranges[j])] + 1, dp[i]);
            }
        }
        int count = min(dp[n], dp[n + 1]);
        return count == INT_MAX ? -1: count;
    }
};