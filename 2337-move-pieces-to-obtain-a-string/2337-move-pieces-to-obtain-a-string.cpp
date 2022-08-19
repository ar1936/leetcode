class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0,n=target.size();
        while(i<=n && j<=n){
            while(i<n && start[i]=='_') i++;
            while(j<n && target[j]=='_') j++;
            
            if(i==n|| j==n)
                return i==n && j==n;
            
            if(start[i]!=target[j])
                return false;
            
            if(target[j]=='L'){
                if(j>i)
                    return false;
            }
            else{
                if(j<i)
                    return false;
            }
            i++;
            j++;
        }
        return true;
    }
};