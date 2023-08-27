class Solution {
public:
    set<pair<int, int>> check_fail; //紀錄計算過的錯誤情況
    unordered_map<int, int> mp;  //紀錄石頭位置
    int termination; // 紀錄終點位置

    bool dfs(vector<int>& stones, int pos, int jump_scale)
    {
        // 走到目的地:成功
        if(pos == termination)
            return true;
        // 該位置不存在石頭
        if(mp.find(pos) == mp.end())
            return false;
        
        // 已知使用該jump_scale跳到pos的情況必不成立，則直接回傳false
        // e.g 已經知道跳到pos = 8 , jump_scale = 5的時候無法抵達終點，則沒有繼續重複計算的必要
        if(check_fail.find({pos, jump_scale}) != check_fail.end())
            return false;

        // 前提是jump_scale要能使pos go forward才會成立
        // first: 往後跳jump_scale - 1長度
        if(jump_scale > 1 && dfs(stones, pos + jump_scale - 1, jump_scale - 1))
            return true;
        // second: 往後跳jump_scale長度
        if(jump_scale > 0 && dfs(stones, pos + jump_scale, jump_scale))
            return true;
        // third: 往後跳jump_scale + 1長度
        if(dfs(stones, pos + jump_scale + 1, jump_scale + 1))
            return true;

        // 該位置和跳轉長度無法成立，加入已知fail條件，並回傳false
        check_fail.insert({pos, jump_scale});
        return false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int m = stones[n-1];
        termination = stones[n-1];

        // 第一步jump_scale無法為1，則直接回傳false
        if(stones[1] - stones[0] != 1)
            return false;

        // 紀錄哪些位置有石頭
        for(auto it: stones)
        {
            mp[it]++;
        }

        return dfs(stones, 0, 0);
    }
};