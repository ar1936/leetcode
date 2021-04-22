class Solution {
public:
    bool solve(int num){
        int temp=num,m;
        while(num!=0){
            int m=num%10;
            
            if(m==0)
            return false;
            
            if(temp%(m)!=0)
                return false;
            
            num=num/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>v;
        for(int i=left;i<=right;i++){
            if(solve(i)==true)
                v.push_back(i);
        }
        return v;
    }
};