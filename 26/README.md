# Leetcode-August-Challenge 8/26
# 646. Maximum Length of Pair Chain
> ## Solution: Greedy
> 題意分析: 
> 1. 給定一串pair資料型態，每個 pair 表示為 [a, b]，其中a < b。
> 2. 定義pair p2 = [c, d] follows pair p1 = [a, b] if b < c.
> 3. 求最長chain (as much follows as it can be)

> Method:
> 1. Sort pair 陣列 (因為這樣能確保greedy選到最長的組合，如果選擇用第一個元素做sorting可能一次會選到很大的區間)
```
    // 依照pair的第二個元素由小到大來排列
    // 若第二個元素皆相同，則依照第一個元素來做排列

    if(a[1] == b[1]) 
        return a[0] < b[0];
    return a[1] < b[1];
```
> 2. 採取greedy策略
```
    int res = 1; // 紀錄chain長度
    int point = 0; // 紀錄chain最尾端對應pair陣列的位置

    // 線性檢查: 
    // 如果當前 pair 有辦法 follow chain 尾端的 pair，則把該元素放入chain中 (長度加一)，並且更新point value。
    // 反之，則直接跳過該pair的檢查。
    for(int i=1; i<pairs.size(); i++)
    {
        if(pairs[i][0] <= pairs[point][1])
        {
            continue;
        }
        point = i;
        res++;
    }
```

> ## Time complexity: O(N * log N)
> 1. sort: O(N * log N)
> 2. Greedy strategy: O(N)
