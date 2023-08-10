# Leetcode-August-Challenge 8/8
# 33. Search in Rotated Sorted Array
> ## Solution: Binary search
> 題意分析: 給定一個Rotated Sorted Array，尋找target number是否存在。若存在，則回傳該target number的index；反之不存在，則回傳-1。  
> Method:
```
    // start binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 找到目標數字回傳index value
        if (nums[mid] == target) return mid;

        // mid值不為rotate pivot的情況
        if (nums[mid] < nums[right]) {
        
            // 再依照target值區分，target落在mid的左半邊還是右半邊，來修正left、right value
            if (nums[mid] < target && nums[right] >= target) left = mid + 1;
            else right = mid - 1;
        }
        // mid值為rotate pivot的情況
        else {
            // 再依照target值區分，target落在mid的左半邊還是右半邊，來修正left、right value
            if (nums[left] <= target && nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
    }
    
    // 找不到目標數字回傳-1
    return -1;
```
> ## Time complexity: O(logN)