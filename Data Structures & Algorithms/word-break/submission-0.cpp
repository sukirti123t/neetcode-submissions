class Solution {
public:
    
        vector< int> dp;
        bool dfs(int i ,string& s, vector<string>& wordDict){
            if(i== s.size())
            return true;
              if(dp[i]!= -1)return dp[i];
            for(string word: wordDict){
            if(i+word.size()<=s.size()){
            
            if(s.substr(i,word.size())== word){
                if(dfs(i+word.size(),s,wordDict)){

dp[i]=1;
return true;
                }

            }
            }
            }
            dp[i]=0;
            return false;}
          
            bool wordBreak(string s, vector<string>& wordDict) {
                dp.resize(s.size(),-1);
                return dfs(0,s,wordDict);
        }
            };
