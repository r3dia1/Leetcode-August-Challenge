# Leetcode-August-Challenge 8/11
# 518. Coin Change II
> ## Solution: dynamic programming
> 題意分析: 給定一組硬幣幣值，計算總金額maount可以被多少種方式組合而成。
> method:
>> 1. 建立dp[n][amount]陣列，代表包含前n種硬幣時，總數為amount時有幾種組合方式。  
>> 2. 利用double for loop來建立dp
```
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=amount; j++)
        {
            // 核心方法
            // 若是當前 amount > 第n種幣值
            // 則所求為: 在包含n種幣值的情況下扣掉該幣值一次的方法數 + 包含n-1種幣值的情況下該幣值的方法數
            // 反之，則所求為包含n-1種幣值的情況下該幣值的方法數 (因為此時amount連一個新幣值都容納不下)
            if((j - coins[i-1]) >= 0)
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

```

> ## Time complexity: O(n * amount)