# Leetcode-August-Challenge 8/27
# 403. Frog Jump
> ## Solution: DFS
> 題意分析: 一隻青蛙想要過河，我們有所有石頭的位置，藉由以下條件跳躍:
>> 1. 青蛙第一次跳躍距離只能為1
>> 2. 青蛙每次跳躍需要根據上一次跳躍距離length，下一次跳躍距離有三種選擇[jump - 1, jump, jump + 1]
>> 3. 求青蛙是否能藉由這些石頭過河?

> Method: 從起點開始根據三種跳躍方法做深度搜尋
```
    bool dfs(vector<int>& stones, int pos, int jump_scale)
    {
        // 走到目的地:成功
        if(pos == termination)
            return true;
        // 該位置不存在石頭
        if(mp.find(pos) == mp.end())
            return false;
        
        // 已知使用該jump_scale跳到pos的情況必不成立，則直接回傳false
        // e.g 已經知道跳到pos = 8 , jump_scale = 5的時候無法抵達終點，則沒有繼續重複計算的必要
        if(check_fail.find({pos, jump_scale}) != check_fail.end())
            return false;

        // 前提是jump_scale要能使pos go forward才會成立
        // first: 往後跳jump_scale - 1長度
        if(jump_scale > 1 && dfs(stones, pos + jump_scale - 1, jump_scale - 1))
            return true;
        // second: 往後跳jump_scale長度
        if(jump_scale > 0 && dfs(stones, pos + jump_scale, jump_scale))
            return true;
        // third: 往後跳jump_scale + 1長度
        if(dfs(stones, pos + jump_scale + 1, jump_scale + 1))
            return true;

        // 該位置和跳轉長度無法成立，加入已知fail條件，並回傳false
        check_fail.insert({pos, jump_scale});
        return false;
    }
```

> Time complexity: O(N^2)