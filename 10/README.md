# Leetcode-August-Challenge 8/10
# 81. Search in Rotated Sorted Array II
> ## Solution: Binary search
> 題意分析: 給定一個Rotated Sorted Array(允許重複數字存在)，尋找target number是否存在。若存在，則回傳該true；反之不存在，則回傳false。  
> Method: 
>> 1. 與之前的"33. Search in Rotated Sorted Array"相同，不過我們需要處裡重複數字的例外情況。
>> 2. 當[2, 2, 5, 2]這種數列出現時，取mid = (left + right)/2會發現num[mid] = num[right]。
>> 3. 此時，我們只需要將right向左移動即可，其餘情況照舊。

>## Time complexity: O(logN)