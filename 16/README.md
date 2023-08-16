# Leetcode-August-Challenge 8/16
# 239. Sliding Window Maximum
> Solution: pair & priority queue
> 題意分析: 對給定的數列做sliding window，並且在每次平移中紀錄window內的最大數值 (window寬度為k)
> ![image](https://github.com/r3dia1/Leetcode-August-Challenge/blob/main/16/example.png)

> Method: 
>> 1. 宣告一個 priority_queue<pair<int, int>> pq 用來紀錄當前window內的數字以及其index，並數字由大到小排序。  
>> 2. 一開始先建立初始window。  
>> 3. 再來利用for loop開始進行sliding window的平移過程。  
>> 4. 每次平移時，先記錄priority queue裡的最大值 (放入vector res)。  
>> 5. 接著檢查當前pq內的最大值是否存在window以外的數字，若是有則全數移出。  
>> 6. 最後把新數字放入pq內做max heap (priority queue)。  
>> 7. 平移到底時回傳res即為所求。  

> 補充:
>> 1. 若是每次平移都重新建立priority queue會超出時間限制(TLE)，所以要重複利用並更新。  
>> 2. pq內可以能會存在out of window的數字，但那些數字都不是最大值，所以不會影響當前window取值的結果。  

> ## Time complexity:
>> 1. 建立初始window pq花費: O(k)  
>> 2. push & pop number in for loop : O((N-k) * logN)  
>> 3. 所以**Total cost = O(N * logN)** 
