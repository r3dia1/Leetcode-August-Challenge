# Leetcode-August-Challenge 8/18
# 1615. Maximal Network Rank
> ## Solution: hash + greedy strategy
> 題意分析: 存在n個城市，給定所有彼此相連的道路資訊roads。任意選擇兩個城市，求出可能擁有最多連接道路的值?

> Method: 
>> 1. Construct a adjacent matrix for each city.  
>> 2. Sort each row (city) from connecting with the most to the least cities.  
>> 3. Take the greedy strategy, we choose the first two cities with the most links and computes their sum as the answer.

> Note:
>> 1. We should consider all possiblities when there exists more than
one cities with the same number of links.  
>> 2. When calculating the sum, we should remove the duplicate links.    
>> (e.g. 如果選擇city[0]和city[1]且存在road(0,1)，則計算總和時，必須扣掉重複計算的1次)  
>> 3. Use the hash table to check if the duplicate link exists.  

> ## Time complexity: 
>> 1. construct adj matrix: O(n^2) //worst case  
>> 2. sort: O(nlogn)  
>> 3. greedy: O(n^2) //worst case  