# Leetcode-August-Challenge 8/30
# 2366. Minimum Replacements to Sort the Array
> ## Solution: Greedy
> 題意分析: 給定一數列，每個元素 z 所在位置可以被 x 、 y 兩元素所取代 (z = x + y)。試問最少要做幾次replacement，才能使該數列呈現non-decreasing order?

> 解題思路: 
> 1. **該數列的最後一個元素必不會被replace //Keypoint**
>    // 因為該數字若是遭到replace，代表元素的最大上限變得更小，需要做更多的分割
> 2. 所以，我們可以從數列的最尾端開始往前做檢查 & 數字分割。
> 