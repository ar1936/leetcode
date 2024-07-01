class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        //if(arr.size()<3)
          //  return false;
        
        for(int i=2;i<arr.size();i++)
        {
            
            int count=0;
            if(arr[i]%2!=0)
                count++;
            if(arr[i-1]%2!=0)
                count++;
            if(arr[i-2]%2!=0)
                count++;
            if(count==3)
                return true;
        }
        return false;
        
    }
};