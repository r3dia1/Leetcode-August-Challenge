# Leetcode-August-Challenge 8/29
# 2483. Minimum Penalty for a Shop
> ## Solution: Linear update
> 題意分析: 
> 1. 給定一個顧客光顧時間表(string)，包含'Y'和'N'。
>   // Y: customers come at that hour.
>   // N: customers do not come at that hour.
> 2. 計算幾點關店，會有最小的penalty? penalty計算方法如下
>   // For every hour when the shop is open and no customers come, the penalty increases by 1.
>   // For every hour when the shop is closed and customers come, the penalty increases by 1.
    

> Method: 
> 1. Calculate the penalty of closing the shop at the 0-th hour.  
> 2. Calculate the penalty of each closing hour by modifying the 0-th hour penalty:  
>> (a) If customers[i] == 'Y' then reduce the penalty by 1.  
>> (b) If customers[i] == 'N' then increase the penalty by 1.  
> 3. Keep update the minmum penalty and its closing hour during step 2.  
> 4. Return the earliest hour with minimum penalty.  

> ## Time complexity: O(N)