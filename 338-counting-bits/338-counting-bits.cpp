class Solution {
    int solve(int n){
        int count=0;
        while(n){
            if(n%2==1)
                count++;
            n/=2;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};