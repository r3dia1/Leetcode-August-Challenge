class Solution {
public:
    vector<vector<int>> dp;
    void dfs(vector<vector<int>>& grid, int m, int n)
    {
        if(grid[m-1][n-1] == 1)
        {
            dp[m][n] = 0;
            return;
        }
        
        if(m == 0 || n == 0)
        {
            dp[m][n] = 0;
            return;
        }
        else if(m == 1 && n == 1)
        {
            dp[m][n] = 1;
            return;
        }

        if(dp[m][n] != -1)
            return;
        
        dp[m][n] = 0;
        if(m-1 > 0)
        {
            dfs(grid, m-1, n);
            dp[m][n] += dp[m-1][n];
        }
        if(n-1 > 0)
        {
            dfs(grid, m, n-1);
            dp[m][n] += dp[m][n-1];
        }
        return;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.resize(m+1, vector<int>(n+1, -1));
        dfs(obstacleGrid, m, n);
        return dp[m][n];
    }
};