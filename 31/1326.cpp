class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first < b.first;
    }

    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> interval;
        for(int i=0; i<n+1; i++)
        {
            interval.push_back({i - ranges[i], i + ranges[i]});
        }

        sort(interval.begin(), interval.end(), cmp);

        int left = 0;
        int right = n;
        int ans = 0;
        while(left < right)
        {
            int temp = left;
            for(auto it: interval)
            {
                if(it.first > left)
                    break;
                
                if(it.second > temp)
                {
                    temp = it.second;
                }
            }

            if(temp != left)
                ans++;
            else
                return -1;
            left = temp;
        }

        return ans;
    }
};