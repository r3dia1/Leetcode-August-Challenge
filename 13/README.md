# Leetcode-August-Challenge 8/13
# 2369. Check if There is a Valid Partition For The Array
> ## Solution: DFS
> 題意分析: 給定一組數列，檢查該數列是否可以切割成不同子數列，且每個子數列均至少滿足下列一種條件:
>> 1. 若子數列長度為2，則該數列內的元素完全相同。 
>> 
>> 2. 若子數列長度為3，則該數列內的元素完全相同。  
>>
>> 3. 若子數列長度為3，則該數列內的元素呈現consecutive increasing。 (e.g [3,4,5])

>> ## O(N^2) method : partition
>> 1. 把整個數列拆分成兩種情況去遞迴檢查三個條件:
```
    // 假設數列長度為n
    // 第一種情況，把數列拆成(2, n-2)去檢查
    // 若是連前2個數字組成的數列 or 後n-2的數字組成的數列都無法滿足條件，則回傳false
    if(!check(nums, start, start + 1) || !check(nums, start + 2, end))
    {
        // 第二種情況，把數列拆成(3, n-3)去檢查
        // 若是連前3個數字組成的數列 or 後n-3的數字組成的數列都無法滿足條件，則回傳false
        if(!check(nums, start, start + 2) || !check(nums, start + 3, end))
            return dp[start][end] = 0;
    }

    // 該數列滿足條件，回傳true
    return dp[start][end] = 1;
```
>>
>> 2. 這樣遞迴可能會產生重複計算的問題，所以我需要透過2D memorization來避免重複計算 (程式裡面的dp)
>>
>> 3. 可能會TLE或是MLE: 當數列龐大的時候dp空間會很龐大會造成MLE的問題 (testcase passed 60/118)

>> ## O(N) method : linear recursion
>> 1. 把partiotion的步驟簡化，變成在三個條件裡面做遞迴。
```
    // 從index=0開始檢查 (需要一個flag來紀錄現在檢查到哪個數字)
    // 每當一個條件符合，代表該子數列成功切割，則更新flag且繼續往下遞迴檢查。  
    // 直到flag指到數列尾端時，代表所有子數列都至少滿足一個條件。
    // 反之，若是無法繼續切割，代表切割失敗回傳false。

    // first condition
    if (i + 1 < n && v[i] == v[i + 1])
    {
        if (c(v, dp, i + 2))
            return dp[i] = true;
    }

    // second condition
    if (i + 2 < n && v[i] == v[i + 2] and v[i] == v[i + 1])
    {
        if (c(v, dp, i + 3))
            return dp[i] = true;
    }

    // third condition
    if (i + 2 < n && v[i] + 1 == v[i + 1] && v[i] + 2 == v[i + 2])
    {
        if (c(v, dp, i + 3))
            return dp[i] = true;
    }

    // false
    return dp[i] = false;
```
>> 
>> 2. 至於對遞迴的剪枝也只需要1D memorization來輔助即可 (因為是linear solution)  
>> 
>> 3. Time complexity: O(N) & Space complexity : O(N)