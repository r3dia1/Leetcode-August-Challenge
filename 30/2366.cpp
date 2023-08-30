class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();

        long long rp_count = 0;
        long long last_check = nums[n - 1];
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] > last_check)
            {
                long long temp = nums[i] / last_check;
                if(nums[i] % last_check != 0)
                {
                    temp++;
                    last_check = nums[i] / temp;
                }
                rp_count += temp - 1;
            }
            else
                last_check = nums[i];
        }

        return rp_count;
    }
};