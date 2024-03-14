class Solution {
public:
    bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1,0));
        //base case
        dp[0][0] = 1;

        for(int i = 0; i<=s.size(); ++i)
            for(int j = 1; j<=p.size();++j)
            {
                if(i==0){
                    if(p[j-1]=='*') dp[i][j]=dp[i][j-2];
                    else dp[i][j] = false;
                }
                else if(p[j-1]=='*')
                {
                    bool res = false;
                    if(p[j-2]==s[i-1] || p[j-2]=='.') dp[i][j] = dp[i][j]||dp[i-1][j];
                    dp[i][j] = dp[i][j]||dp[i][j-2];
                }
                else if(p[j-1]=='.' || p[j-1]==s[i-1]) dp[i][j] = dp[i-1][j-1];
            }
        return dp[s.size()][p.size()];  
    }
};