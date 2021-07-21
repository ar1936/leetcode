class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),x=0,y=0;
        vector<vector<bool>>v(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            int i=0,j=gap;
            while(j<n){
                if(gap==0){
                    v[i][j]=true;
                }
                else if(gap==1){
                    if(s[i]==s[j]){
                        v[i][j]=true;
                    }
                }
                else{
                    if(s[i]==s[j]&&v[i+1][j-1])
                        v[i][j]=true;
                }
                if(v[i][j]){
                    x=i;
                    y=j;
                }
                
                i++;
                j++;
            }
        }
        string ans="";
        if(x>y){
            swap(x,y);
        }
        for(int i=x;i<=y;i++){
           ans+=s[i];
        }       
        return ans;
    }
};