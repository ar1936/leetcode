class Solution {
    int get_count(int n){
        int count=0;
        while(n!=1){
            if(n%2==0)
                n/=2;
            else if(n%2!=0)
                n=3*n+1;
            count++;
        }
        return count;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
        for(int i=lo;i<=hi;i++){
            v.push_back({get_count(i),i});
        }   
        sort(v.begin(),v.end());
        int ans=0;
        for(auto x:v){
            k--;
            ans=x.second;
            if(k==0)
                break;
        }
        return ans;
    }
};