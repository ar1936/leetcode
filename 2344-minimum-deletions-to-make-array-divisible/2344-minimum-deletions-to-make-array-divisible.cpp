class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int gcd=0,ind=0;
        if(b.size()==1)
            gcd=b[0];
        else
            gcd=__gcd(b[0],b[1]);
        for(int i=1;i<b.size();i++){
            gcd =__gcd(gcd,b[i]);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            if(gcd%a[i]==0)
                return i ;
        }
        return -1;
    }
};