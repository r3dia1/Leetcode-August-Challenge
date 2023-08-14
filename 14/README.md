# Leetcode-August-Challenge 8/14
# 215. Kth Largest Element in an Array
> ## Solution: Priority Queue
> 題意分析: 給定一數列，在不進行排序的情況下找出第k大的元素。  
> Method: 把所有元素放入priority queue(max-heap)，做k次pop回傳即為所求。  
> ## Time complexity
>> 1. Build max heap takes O(N) times.  
>> 2. Each pop & adjust takes O(logN) times * k = O(k * logN)
