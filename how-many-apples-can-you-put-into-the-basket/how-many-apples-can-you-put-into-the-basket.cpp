class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        int count=0,weight=5000;
        sort(arr.begin(),arr.end());
        while(true)
        {
            if(count==arr.size())
            {
                break;
            }
            weight-=arr[count];
            if(weight<0)
                break;
            count++;
        }
        return count;
    }
};