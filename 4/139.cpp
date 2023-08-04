class Solution {
public:
    vector<int> dp;
    int dp_sol(int i, string& s, unordered_map<string, int>& m){
        if(i==s.size()) return 1;

        if(dp[i]!=-1) return dp[i];
        string temp = "";
        for(int j=i;j<s.size();++j){
            temp+=s[j];
            if(m.count(temp)){
                if(dp_sol(j+1, s, m)) return dp[j+1] = 1;
            }
        }

        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, int> m;
        dp.resize(301, -1);
        for(auto x:wordDict) m[x]++;

        return dp_sol(0, s, m);
    }
};