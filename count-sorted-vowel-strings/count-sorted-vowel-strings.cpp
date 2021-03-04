class Solution {
public:
    //  Backtracking solution  :)   
    
    
        void solve(int i,int &n,int len){
        if(n==len){
            count+=1;
            return;
        }
        for(int j=i;j<5;j++){
            solve(j, n, len+1);
        }
        return;
    }

    int count = 0;
    int countVowelStrings(int n) {
        count=0;
        solve(0,n,0);
        return count;
    
    }

};
