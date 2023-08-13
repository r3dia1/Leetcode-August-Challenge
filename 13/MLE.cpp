class Solution {
public:
    vector<vector<int>> dp;
    bool check(vector<int>& nums, int start, int end)
    {
        int length = end - start + 1;
        if(length == 1)
        {
            dp[start][end] = 0;
            return false;
        }

        if(dp[start][end] != -1)
            return dp[start][end];
        
        if(length == 2)
        {
            if(nums[start] == nums[end])
                return dp[start][end] = 1;
            else
                return dp[start][end] = 0;
        }
        else if(length == 3)
        {
            if((nums[start] == nums[start+1]) && (nums[start] == nums[end]))
                return dp[start][end] = 1;
            else
            {
                if((nums[start]+1 == nums[start+1]) && (nums[start]+2 == nums[end]))
                    return dp[start][end] = 1;
                else
                    return dp[start][end] = 0;
            }
        }
        
        if(!check(nums, start, start + 1) || !check(nums, start + 2, end))
        {
            if(!check(nums, start, start + 2) || !check(nums, start + 3, end))
                return dp[start][end] = 0;
        }

        return dp[start][end] = 1;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        bool res = check(nums, 0, n-1);
        return res;
    }
};