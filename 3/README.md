# Leetcode-August-Challenge 8/3
# 17. Letter Combinations of a Phone Number
> ## Solution: recursive
> 1. 題意分析: 給定一串數字，每個數字對應到一組不同英文字母組成的陣列。求出該串數字可能產生的所有英文字母陣列組合。  

> 2. Method: 
```
    // 一種字母組合建立完成後，便把他轉換成string型態並回傳
    if(index == digits.size())
        {
            string str(temp.begin(), temp.end());
            if(str != "") // 注意: 若是該結果為空則不要將其加入回傳結果
                ret.push_back(str);
            return;
        }

        // 找出當前數字為何?
        char idx = digits[index];
        // 遍歷當前數字所對應之英文字母組合
        for(int i=0; i<phone[idx].size(); i++)
        {
            // 選取該字母並加入組合中
            temp.push_back(phone[idx][i]);
            // 繼續選取下一個數字所對應之字母們
            mycombination(digits, temp, phone, index + 1);
            // 當前選擇該字母的所有情況已經建立完畢，所以歸還 & 繼續往其他字母建立組合
            temp.pop_back();
        }
        return;
```

> ## Time complexity: worst case = O(4^N)
> e.g. digits = "9999" or "7777" 每個字母需要遍歷4種可能
