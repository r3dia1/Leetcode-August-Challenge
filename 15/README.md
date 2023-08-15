# Leetcode-August-Challenge 8/15
# 86. Partition List
> ## Solution: Merge two sub link list
> 題意分析: 給定一數列和數字x，重新排序出一個新數列 (左半邊數字皆小於x，右半邊數字皆大於等於x)，且要抱持原數列數字之間的相對位置。  
> Method:
> 1. From head to tail create two sublist :
>> sub1: less than number x  
>> sub2: greater than or equal to number x
> 2. Merge them together and return.  
> ## Time complexity: O(N)
