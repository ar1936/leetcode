
class Solution {
public:
    
    int dp[12][2][2];
    int solve(vector<int> &v,int pos,int tight,int st,string &s){
        if(pos == s.size()) return 1;
        else if(dp[pos][tight][st] != -1)
            return dp[pos][tight][st];
        
        int ans = 0;
		
		          // if value is not started yet then we have two choice we can leave the current digit
				  // or start from here 
        if(st == 0){
            int en = tight?(s[pos] - '0') : 9;  // take the upper limit 
            ans = solve(v,pos + 1,0,0,s);    // leave the current digit 
            for(int i=0; i<v.size(); i++){
                if(v[i] > en) continue;       // if current digit is greate then limit then go for next number 
                ans += solve(v,pos + 1, tight&(en==v[i]),1,s);  // start the number thats why st = 1 value is started 
            }
        }
        else{   
		                    // if number is started the we can place the digits those who cames under limit
            int en = tight?(s[pos] - '0') : 9;
            for(int i=0; i<v.size(); i++){
                if(v[i] > en) continue;
                ans += solve(v,pos + 1,tight&(en==v[i]),st,s);
            }
        }
        return dp[pos][tight][st] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        vector<int> v(digits.size(),0);  
		
		                  // i have converted string array to int array for easy 
        for(int i=0; i<digits.size(); i++){
            char ch = digits[i][0];
            v[i] = ch - '0';
        }
        
        memset(dp,-1,sizeof dp);
        
        
            // subtract one because 0 is also counted in result 
        return solve(v,0,1,0,s) - 1;
    }
};
