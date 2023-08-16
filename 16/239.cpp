class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();

        priority_queue<pair<int, int>> pq;
        for(int i=0; i<k; i++)
        {
            pq.push({nums[i], i});
        }

        int pop;
        for(int i=k; i<n; i++)
        {
            pop = pq.top().first;
            res.push_back(pop);

            while (!pq.empty() && pq.top().second <= i - k) 
                pq.pop();
            pq.push({nums[i], i});

        }
        pop = pq.top().first;
        res.push_back(pop);
        return res;
    }
};