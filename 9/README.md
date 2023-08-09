# Leetcode-August-Challenge 8/9
# 2616. Minimize the Maximum Difference of Pairs
> ## Solution: Binary search + Greedy
> **題意分析:** Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. 
>> e.g. [10, 1, 2, 7, 1, 3] , p = 2  
>> 選取 pair (1, 1) (2, 3) 會有最小的 max ( pair difference )

> **Method:**
>> 1. 把nums陣列重新排序，並且選取(最大 - 最小元素值)作為binary search的上界  
>> 2. 進行binary search，每一次都檢查欲選取的值(中間值)是否合法?  
![image](https://github.com/r3dia1/Leetcode-August-Challenge/blob/main/9/greedy%20algo.jpg)  
>> 3. 每次找到的pair數量必須等於p，該選取值才算合法  
>> 4. binary search直到結束並回傳  

> **Error greedy method:**
>> 若不是選用循序檢查的方法，而是採用pair's diff越小優先選擇的local optimal方法並不會得到最佳解。  
>> 舉 [1, 3, 3, 5] & p = 2為例，  
>> Error: 選(3, 3)再選(1, 5)，所求為max(0, 4) = 4  
>> Correct: 選(1, 3)再選(3, 5)，所求為max(2, 2) = 2 //return  

> ## Time complexity: O(N * logK)
>> 1. Binary search takes O(logK) // K is (max element - min element)  
>> 2. For each search takes O(N) // N is the nums' length  
>> 3. So the time complexity is O(N * logK)
