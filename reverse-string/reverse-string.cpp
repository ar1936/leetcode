class Solution {
public:
    void reverseString(vector<char>& s) {
        // char temp;
        // int n=s.size();
        // if(n==1)
        //     return ;
        // for(int i=0;i<=n/2;i++)
        // {
        //     temp=s[i];
        //     s[i]=s[n-i-1];
        //     s[n-1-i]=temp;
        // }
    
        reverse(s.begin(),s.end());
        
    }
};