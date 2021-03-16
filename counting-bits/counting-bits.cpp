class Solution {
public:
    int  number_of_set_bit(int n)
    {
        if(n==0)
            return 0;
        int count=1;
        while(n>1)
        {
            if(n%2==1)
                count++;
            n/=2;
            
        }
        return count;
    }
    vector<int> countBits(int num) {
     vector<int>t(num+1,0);
        // memset(t,0,sizeof(t));
        for(int i=1;i<=num;i++){
        if(t[i]==0)
            t[i]=number_of_set_bit(i);
        }
        return t;
    }
};