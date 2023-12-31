# Leetcode-August-Challenge 8/17
# 542. 01 Matrix
> ## Solution: BFS(多源最短路徑)
> 題意分析: 給定一個由0/1組成的矩陣，找出每個元素到最近0的距離。(兩個相鄰元素間的距離為1)  

> Method: 多源最短路徑 ---> 單源最短路徑
>> 1. 最直覺的方法: 我們可以針對每個元素值為1的位置，做BFS的搜索直到遇到0，並記錄距離。   
>> 不過，這個方法一次BFS只能找出一個元素的距離，效率很差。  
>>
>> 2. 所以，我們要改對0做BFS的搜索，如圖所示像是雷達一樣 (第一圈碰到帶有元素1的位置，其到0的距離為1，以此類推)  
>> ![image](https://github.com/r3dia1/Leetcode-August-Challenge/blob/main/17/image.png)
>>
>> 3. 然而，我們又可以想像一開始所有的0，被一個超級源點所連結，就此轉變為一個單源最短路徑問題。  
>> ![image](https://github.com/r3dia1/Leetcode-August-Challenge/blob/main/17/image-1.png)
>>
>> 4. 演算法如下:
>> ```
>>     1. 初始化一個紀錄距離的矩陣dist，其中所有0的距離為0，所有1的距離為INT_MAX
>> 
>>     2. 宣告一個queue用於BFS，並且把所有0的位置存入queue
>>
>>     3. 依序pop出queue裡的元素{i, j}，並檢查其鄰居{t_i, t_j}
>>
>>     4. 如果新計算出來的距離dist[i][j] + 1 < dist[t_i][t_j]，則更新dist[t_i][t_j]的距離並把該位置存入queue
>>        // 只有元素1的位置會被更新，因為初始值為int_max
>>
>>     5. 直到queue為空，代表dist建立完成
>> ```

> ## Time complexity: O(m * n) //因為距陣中的每個元素只被放入queue一次
> 參考資料: 542. 01 Matrix 01 矩阵【LeetCode 力扣题解】(https://www.youtube.com/watch?v=YTnYte6U61w)
