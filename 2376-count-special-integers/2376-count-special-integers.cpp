class Solution {
     int dp[11][2][1024];
    
    int gogo(string &s, int tight = 1, int pos = 0, int mask = 0) {
        // Base case
        if(pos == s.size()) {
            // Mask = 0, represents 00000...0 which should not be counted
            return mask != 0;
        }
        
        // DP state
        if(dp[pos][tight][mask] != -1)
            return dp[pos][tight][mask];
        
        int ans = 0;

        if(tight == 1) {
            
            // Limit the current digit
            for(int i = 0; i <= s[pos] - '0'; i++) {
                
                // Check if digit repeated, ie, present in the mask
                if(mask & (1 << i)) continue;
                
                int newMask=0;
                
                if(mask != 0 || i !=0 )
                {
                	newMask = mask | (1 << i);
                }
                else{
                    newMask = mask;
                }
                
                if(i == s[pos] - '0') {
                    // Tight case
                    ans += gogo(s, 1, pos + 1, newMask);
                } else {
                    ans += gogo(s, 0, pos + 1, newMask);
                }
            }
        } else {
            for(int i = 0; i <= 9; i++) {
                
                // Check if digit repeated, ie, present in the mask
                if(mask & (1 << i)) continue;
                
                int newMask = 0;
                if(mask != 0 || i !=0 )
                {
                	newMask = mask | (1 << i);
                }
                else{
                    newMask = mask;
                }
                
                ans += gogo(s, 0, pos + 1, newMask);
            }
        }
        return dp[pos][tight][mask] = ans;
    }
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return gogo(s);
    }
};