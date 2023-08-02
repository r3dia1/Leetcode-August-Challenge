# Leetcode-August-Challenge 8/2
# 46. Permutations
> ## Solution: recursive for permutation
> 1. 題意分析: 給定一串數列，回傳他所有可能的排列方式  

> 2. 宣告一個2D array permu來記錄結果，並且宣告一個check陣列來記錄當前數字是否已經被選用  

> 3. Recursive method:
```
    // 利用迴圈設置不同的開頭數字，再開始對其做排列
    for(int i=0; i<length; i++)
    {
        // 若是當前數字尚未被選用過，則納入選擇
        if(!check[i])
        {
            // 把check[i] flag設置成true (選用)
            check[i] = true;

            // 把該數字納入當前排列結果
            temp.push_back(nums[i]);

            // 繼續選擇下一個數字直到全部都選過為止
            mypermutation(temp, length, nums);

            // 會進行到這步，代表已經完成一種排列結果
            // 所以要歸還該數字，以建立其他排列結果
            temp.pop_back();
            check[i] = false;
        }
    }
```

> ## Time complexity: O(N^2)
