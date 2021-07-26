class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size()+1,ans=0;
        vector<int>pre(n);;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^arr[i-1];
        }
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                if(pre[i]==pre[k]){
                    ans+=k-i-1;
                }
            }
        }
        return  ans;
        
    }
};