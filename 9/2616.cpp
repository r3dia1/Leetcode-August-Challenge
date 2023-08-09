class Solution {
public:
    bool test(int bound, vector<int> num, int p)
    {
        int count = 0;
        int n1 = 0, n2 = 1;
        while(n2 < num.size() && count != p)
        {
            if((num[n2] - num[n1]) <= bound)
            {
                count++;
                n1 += 2;
                n2 += 2;
            }
            else
            {
                n1++;
                n2++;
            }
        }
        return (count == p);
    }   

    int minimizeMax(vector<int>& nums, int p) {
        if(nums.size() == 0 || p == 0)
            return 0;

        sort(nums.begin(), nums.end());
        int bound = nums[nums.size() - 1] - nums[0];
        int diff_count;

        int l = 0, r = bound;
        while(l < r)
        {
            int mid = (l + r)/2;
            if(test(mid, nums, p))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return r;
    }
};