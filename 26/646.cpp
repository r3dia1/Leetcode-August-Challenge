
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[1]==b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        
        // for(auto &x: pairs)
        // {
        //     for(auto y: x)
        //         cout << y << " ";
        //     cout << endl;
        // }

        int res = 1;
        int point = 0;
        for(int i=1; i<pairs.size(); i++)
        {
            if(pairs[i][0] <= pairs[point][1])
            {
                continue;
            }
            point = i;
            res++;
        }

        return res;
    }
};