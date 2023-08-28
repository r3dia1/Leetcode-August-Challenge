# Leetcode-August-Challenge 8/28
# 225. Implement Stack using Queues
> ## Solution: priority queue
> 題意分析: 使用queue來模擬stack的行為 (只能使用queue的各種operations)
> Method:
>> 1. 若是使用一般的queue，則在 top()、pop()、empty() 時，需要遍歷所有元素，費時 O(N)  
>> 2. 若改為使用priority_queue<pair<counter, number>>，利用counter把最新的元素放在開頭，最舊的元素放在尾端，則只需花費O(1)即可  
>> 3. 其他operation與queue的push()無異

> ## Time complexity:
| :-----: | :-----: |
| push | O(1) |
| pop | O(1) |
| top | O(1) |
| empty | O(1) |
