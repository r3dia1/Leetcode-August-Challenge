# Leetcode-August-Challenge 8/31
# 1326. Minimum Number of Taps to Open to Water a Garden
> ## Solution 1 : Greedy
> 題意分析: 
> 在一座一維長度(0 ~ n)的花圃中，在每個單位點上都設有灑水器。  
> 每個灑水器的噴灑範圍為[i - ranges[i], i + ranges[i]]。  
> 求最少使用多少個灑水器範圍可以覆蓋整個花圃?
>
> Method: 
> 1. 先建立所有灑水器的範圍之陣列interval，並以left end point做排序。  
> 2. 接著，我們想要採取Greedy策略來選擇灑水器覆蓋個花圃。  
> 3. 從interval陣列最左端開始選取能夠覆蓋最大範圍的灑水器，直到能覆蓋整個花圃即完成。  
> 4. 若是選了全部灑水器都不能覆蓋整個花圃，則回傳失敗 -1。  
>
> ## Time Complexity: worst O(N^2) // 不常發生worst case

> ## Solution 2 : Dynamic programming
> Method:
> 1. 建立一個長度為 n+2 的 dp 陣列，用來記錄花圃覆蓋使用灑水器數量之最佳解。  
> 2. 從座標位置 = 1開始往後做更新dp的檢查:
> ```
>    for(int i=1; i<n+2; i++)
>    {
>        // 每次都重新檢查位置0 ~ i的灑水器能不能夠覆蓋當前長度i
>        for(int j=0; j<i; j++)
>        {
>            // 因為每個灑水器的範圍為[j - ranges[j], j + ranges[j]]
>            // 所以，檢查dp[j - ranges[j]] 是否已經被更新過，且加上j-th灑水器後是否能覆蓋長度i
>            // 然而 j - ranges[j]可能會產生負數，如果為負數則直接改檢查index 0
>
>            if(dp[max(0, j - ranges[j])] < INT_MAX && j + ranges[j] >= i)
>                dp[i] = min(dp[max(0, j - ranges[j])] + 1, dp[i]);
>        }
>    }
> ```
>
> ## Time complexity: alwas O(N^2) // 效率很差
