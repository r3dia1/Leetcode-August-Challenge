class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();

        int rp_count = 0;
        long long last_check = nums[n - 1];
        for(int i=n-2; i>=0; i--)
        {
            cout << endl;
            cout << "nums[i] = " << nums[i] << endl;
            if(nums[i] > last_check)
            {
                cout << "last = " << last_check << endl;
                long long temp;
                long long remain = (nums[i] + last_check - 1) % last_check;
                // cout << "(nums[i] + last_check - 1) = " << (nums[i] + last_check - 1) << endl;
                long long last = last_check;
                while(1 && last_check > 1)
                {
                    temp = (nums[i] + last_check - 2) % (last_check - 1);
                    cout << "remain = " << remain << endl;
                    cout << "temp = " << temp << endl;
                    if(temp <= remain)
                    {
                        last_check--;
                        continue;
                    }
                    else
                    {
                        remain = temp;
                        last = last_check - 1;
                    }
                }

                rp_count += nums[i] / last;
                if(last == remain + 1)
                    rp_count--;
                // cout << rp_count << endl;
                last_check = remain + 1;
            }
            else
                last_check = nums[i];
        }

        return rp_count;
    }
};