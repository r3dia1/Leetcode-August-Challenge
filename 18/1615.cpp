class Solution {
public:
    static bool mycmp(vector<int>& a, vector<int>& b)
    {
        return a.size() > b.size();
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n);
        
        for(int i=0; i<n; i++)
            graph[i].push_back(i);

        for(auto& i: roads)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        sort(graph.begin(), graph.end(), mycmp);

        int local_max = 0;
        for(int i=1; i<n; i++)
        {
            if(graph[i].size() < graph[0].size())
                break;
            local_max = i;
        }

        int res;
        for(int k=0; k<=local_max; k++)
        {
            int rank = graph[k].size() - 1; 
            unordered_map<int, int> mp;
            for(int i=1; i<graph[k].size(); i++)
                mp[graph[k][i]]++;
            
            int len;
            int max = 0;
            for(int i=0; i<n; i++)
            {
                if(i == k)
                    continue;
                len = graph[i].size();
                int temp = len - 1;
                if(mp.find(graph[i][0]) != mp.end())
                    temp--;
            
                if(temp > max)
                    max = temp;

                if(i + 1 < n)
                {
                    if(graph[i+1].size() < len)
                        break;
                }
            }

            if(k == 0)
            {
                res = graph[k].size() - 1 + max;
            }
            else if(res < graph[k].size() - 1 + max)
            {
                res = graph[k].size() - 1 + max;
            }
        }
        return res;
    }
};