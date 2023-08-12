# Leetcode-August-Challenge 8/12
# 63. Unique Paths II
> ## Solution: dynamic prograamming
> 題意分析: 給定一盤規格m * n的網格，機器人要從左上角走到右下角。其中機器人只能往右或往下走，求在避開所有障礙物的情況下共有幾種走法?
> Method: 
>> 1. 基本上我們要利用dp陣列來逐步建立結果，假設當前位置的算法為dp[row][col]
>> 
>> 2. 其中的核心算法: dp[row][col] = dp[row-1][col] + dp[row][col-1]
>> 
>> 3. 因為機器人只能往右or往下走，所以當前的方法數必為上方加上左方的方法數  \
>> 
>> 4. 另外，如果當前位置放的是障礙物，則該位置方法數為0
>> 
>> 5. 所以我們可以透過遞迴的方式去建立dp陣列，並且利用剪枝的方式避免重複計算。

> ## Time complexity: O(n * m)
