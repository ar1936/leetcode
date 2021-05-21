class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        map<int,int>mp;
        if(A.size()==1)
            return A[0];
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
        }
        sort(A.begin(),A.end());
         for(int i=A.size()-1;i>=0;i--){
            if(mp[A[i]]==1)
                return A[i];
        }
        return -1;
    }
    
};