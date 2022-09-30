class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int n=v.size(),low=0,high=n-1;
        bool flag1 = false, flag2 = false;
        if(n==1){
            return 0;
        }
        if(n==2){
            if(v[0]>v[1])
                return 2;
            return 0;
        }
        while(1){
            if(v[low]<=v[low+1]){
                low++;
            }
            else{
                flag1=true;
            }
            if(v[high]>=v[high-1]){
                high--;
            }
            else{
                flag2=true;
            }
            if(flag1&&flag2)
                break;
            if(low>high)
                return 0;
        }
        int windowMin = INT_MAX, windowMax = INT_MIN;
        for (int i = low; i <= high; i++) {
            windowMin = min(windowMin, v[i]);
            windowMax = max(windowMax, v[i]);
        }

        while (low-1 >= 0 && v[low-1] > windowMin) low--;
        while (high+1 <= v.size()-1 && v[high+1] < windowMax) high++;

        return high - low + 1;
        
    }
};