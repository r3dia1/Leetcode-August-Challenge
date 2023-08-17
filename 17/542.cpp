class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 1)
                    dist[i][j] = INT_MAX;
                else
                    q.push({i, j});
            }
        }

        //bfs
        vector<int> direction = {0, -1, 0, 1, 0};
        while(!q.empty())
        {
            int i, j;
            i = q.front().first;
            j = q.front().second;
            q.pop();

            for(int k=0; k<4; k++)
            {
                int t_i = i + direction[k];
                int t_j = j + direction[k+1];
                if(t_i >= 0 && t_i < m && t_j >= 0 && t_j < n)
                {
                    if(dist[t_i][t_j] > dist[i][j] + 1)
                    {
                        dist[t_i][t_j] = dist[i][j] + 1;
                        q.push({t_i, t_j});
                    }
                }
            }
        }

        return dist;
    }
};