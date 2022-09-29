class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        // priority_queue<pair<int,int>>pq;
        // for(int i=0;i<arr.size();i++){
        //     pq.push({abs(arr[i]-x),arr[i]});
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }
        // vector<int>ans;
        // while(pq.empty()==false){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        
        
        
        
        int n = arr.size();
        
        if(k==n){
            return arr;
        }
        if(x<=arr[0]){
            return vector<int>(arr.begin()+0, arr.begin()+k);
        }
        else if(x>=arr[n-1]){
            return vector<int>(arr.begin()+n-k,arr.end());
        }
        else{
            int lo=0,hi=n-1,p=n-k;
            while(p--){
                if(abs(x-arr[lo])>abs(arr[hi]-x))
                    lo++;
                else
                    hi--;
            }
            hi++;
            return vector<int>(arr.begin()+lo, arr.begin()+hi);
        }
    }
};