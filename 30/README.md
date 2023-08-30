# Leetcode-August-Challenge 8/30
# 2366. Minimum Replacements to Sort the Array
> ## Solution: Greedy
> 題意分析: 給定一數列，每個元素 z 所在位置可以被 x 、 y 兩元素所取代 (z = x + y)。試問最少要做幾次replacement，才能使該數列呈現non-decreasing order?

> 解題思路: 
> 1. **該數列的最後一個元素必不會被replace //Keypoint**  
> // 因為該數字若是遭到replace，代表元素的最大上限變得更小，需要做更多的分割  
> 2. 所以，我們可以從數列的最尾端開始往前做檢查 & 數字分割。  
> 3. 然而，我們要如何進行分割才會是最佳解呢? 以下分析三種策略:  
>> 假設數列: "O O O O x y" and x > y  
>> **1. x = y + y + y + y + y + r**   
>> 此時共k次分割(r!=0) , r為餘數 (r亦為下次分割時的partition上限)。  
>> // 這個分割法會有一個問題: r有可能非常小，導致往後的檢查均需要大量的分割，所以該法並非最佳解。  
>>
>> **2. mod法 (每次分割讓y和r差距最小)**   
>> 基於解法1的改良方法: 在每次分割檢查時，慢慢地縮減partition上限 (除數y)，使得餘數r能夠最大。    
>> // 問題: 雖然用這個方法能夠維持partition的上限，但不能確保每次分割的次數會最少  
>>
>> **3. 折衷方案**
>> 基於前兩者的折衷方案:  
>> a. 每次分割改為x = y'+ y'+ y'+ y'+ y'+ y'+ r'(共k + 1個y')，接著我們可以把r'用來來填補y'，使y'變成y。    
>> b. 然而又 x = y + y + y + y + y + r 所以r'必不能填滿所有y' (當y' = r時，頂多填完k個y')  
>> c. 所以，必剩下一個y' >= r作為下個partition上限，而且此處partition次數仍為k。  
>> 結論: 該法能確保在維持partition上限的前題下，維持最少的分割數。  

> ## Time complexity: O(N)
