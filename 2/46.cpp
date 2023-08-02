class Solution {
public:
    vector<vector<int>> permu;
    vector<bool> check; // false represents not been choose
    void mypermutation(vector<int>& temp, int length, vector<int>& nums)
    {
        // 若是已經遍歷所有數字，則把該temp結果納入permu結果並回傳
        if(temp.size() == length)
        {
            permu.push_back(temp);
            return;
        }

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
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        // Initialize check flag
        check.resize(n, false);

        vector<int> temp;
        mypermutation(temp, n, nums);
        
        return permu;
    }
};