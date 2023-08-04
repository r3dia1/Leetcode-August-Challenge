# Leetcode-August-Challenge 8/4
# 139. Word Break
> ## Solution: dynamic programing
> 1. 題意分析: 給定一個字串和一組word dictionary，檢查該字串是否可以由word dictionary裡面的word所構成。  
> 2. method: 
```
    // dp用來判斷當前長度的substring是否可以被wrodDict組合而成 (1代表可以，0則否)
    // 代表成功找到字串組成方法
    if(i==s.size()) return 1;

    // 當前dp已經建立可直接回傳結果
    if(dp[i]!=-1) return dp[i];

    // 一步一步檢查substring是否存在於word dictionary
    string temp = "";
    for(int j=i;j<s.size();++j){
        temp+=s[j];
        // 若是該substring存在於word dictionary，繼續對剩下的substring建立dp
        if(m.count(temp)){
            if(dp_sol(j+1, s, m)) return dp[j+1] = 1;
        }
    }

    //檢查失敗回傳false
    return dp[i] = 0;
```

> ## Time complexity: 
> 1. 對於一般的dp，我們可以使用雙重迴圈來解這個問題，其花費為O(N^2)  
> 2. 但是透過有效的遞迴 & 剪枝(cache)，我們可以在更進一步的縮短runtime。
