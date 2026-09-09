// Basic approach using set

class Solution {
  public:
  
  void fun(string &s1, string &s2, int i, int j,int n, int m, vector<vector<int>> &dp,set<string> &ans,string &str){
      if(i == n || j == m){
          ans.insert(str);
          return;
      }
      
      if(s1[i] == s2[j]){
          str.push_back(s1[i]);
          fun(s1,s2,i+1,j+1,n, m,dp,ans,str);
          str.pop_back();
      }
      else if(dp[i+1][j] > dp[i][j+1])
      fun(s1,s2,i+1,j,n,m,dp,ans,str);
      
      else if(dp[i+1][j] < dp[i][j+1])
      fun(s1,s2,i,j+1,n,m,dp,ans,str);
      
      else{
          fun(s1,s2,i+1,j,n,m,dp,ans,str);
          fun(s1,s2,i,j+1,n,m,dp,ans,str);
      }

      
  }
    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        
        set<string> ans;
        string str = "";
        
        fun(s1,s2,0,0,n,m,dp,ans,str);
        
        vector<string> res;
        for(auto it = ans.begin(); it != ans.end(); it++)
        res.push_back(*it);
        
        return res;
        
    }
};



// Optimised approach using dp
class Solution {
	public:
	
	vector<vector<set<string>> > memo;
	vector<vector<bool>> vis;
	
	set<string> fun(string &s1, string &s2,
	int i, int j,
	int n, int m,
	vector<vector<int>> &dp) {
		
		if (i == n || j == m) {
			return {""};
		}
		
		if (vis[i][j]) {
			return memo[i][j];
		}
		
		vis[i][j] = true;
		
		set<string> ans;
		
		if (s1[i] == s2[j]) {

			set<string> temp =
			fun(s1, s2, i + 1, j + 1, n, m, dp);
			
			for (auto str : temp) {
				ans.insert(s1[i] + str);
			}
		}
		
		else if (dp[i + 1][j] > dp[i][j + 1]) {
			ans = fun(s1, s2, i + 1, j, n, m, dp);
		}
		
		else if (dp[i + 1][j] < dp[i][j + 1]) {
			ans = fun(s1, s2, i, j + 1, n, m, dp);
		}
		
		else {
			set<string> left =
			fun(s1, s2, i + 1, j, n, m, dp);
			
			set<string> right =
			fun(s1, s2, i, j + 1, n, m, dp);
			
			for (auto str : left)
				ans.insert(str);
			
			for (auto str : right)
				ans.insert(str);
		}
		
		return memo[i][j] = ans;
	}
	
	vector<string> allLCS(string &s1, string &s2) {
		
		int n = s1.size();
		int m = s2.size();
		
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				
				if (s1[i] == s2[j]) {
					dp[i][j] = 1 + dp[i + 1][j + 1];
				}
				else {
					dp[i][j] = max(dp[i][j + 1],
					dp[i + 1][j]);
				}
			}
		}
		
		memo.resize(n, vector<set<string>> (m));
		vis.resize(n, vector<bool>(m, false));
		
		set<string> ans =
		fun(s1, s2, 0, 0, n, m, dp);
		vector<string> res;
		
		for (auto it = ans.begin(); it != ans.end(); it++)
			res.push_back(*it);
		
		return res;
	}
};
class Solution {
  public:
  
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m ; j++){
                if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};