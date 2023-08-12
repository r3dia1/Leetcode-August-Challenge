class Solution {
public:
    vector<vector<int>> dp;
    void dfs(vector<vector<int>>& grid, int m, int n)
    {
        if(m == 0 || n == 0)
        {
            dp[m][n] = 0;
            return;
        }

        if(dp[m][n] != 0)
            return;
        

        if((m-1 > 0) && (n-1 > 0) && (grid[m-1][n-1] != 1))
        {
            if(grid[m-2][n-1] == 1)
            {   
                dfs(grid, m, n-1);
                dp[m][n] = dp[m][n-1];
                return;
            }
            else if(grid[m-1][n-2] == 1)
            {
                dfs(grid, m-1, n);
                dp[m][n] = dp[m-1][n];
                return;
            }
            else
            {
                dfs(grid, m-1, n);
                dfs(grid, m, n-1);
                dp[m][n] = dp[m-1][n] + dp[m][n-1];
                return;
            }
        }
        return;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.resize(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++)
        {
            if(obstacleGrid[i-1][0] == 1)
                break;
            dp[i][1] = 1;
        }
        for(int i=1; i<=n; i++)
        {
            if(obstacleGrid[0][i-1] == 1)
                break;
            dp[1][i] = 1;
        }
        dfs(obstacleGrid, m, n);
        // for(auto &it: dp)
        // {
        //     for(auto it1: it)
        //     {
        //         cout << it1 << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m][n];
    }
};