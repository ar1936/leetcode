class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<boxTypes.size();i++){
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize>=pq.top().second){
                ans+=pq.top().first*pq.top().second;
                truckSize-=pq.top().second;
            }
            else if(truckSize>0){
                ans+=truckSize*pq.top().first;
                truckSize=0;
            }
            pq.pop();
        }
        
        return ans;
    }
};