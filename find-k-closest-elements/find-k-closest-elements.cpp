class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int> > heap;
        vector<int>v;
        for(int  i=0;i<arr.size();i++)
        {
            heap.push({abs(arr[i]-x),arr[i]});
            if(heap.size()>k)
                heap.pop();
        }
        while(heap.size()>0){
            v.push_back(heap.top().second);
            heap.pop();
        }
        sort(v.begin(),v.end());
        return v;
        
    }
};