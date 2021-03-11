class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int low=0,high=1;
        if(arr.size()==1)
            return arr[0];
        if(arr[0]!=arr[1])
            return arr[0];
        if(arr[arr.size()-1]!=arr[arr.size()-2])
            return arr[arr.size()-1];
        for(int i=0;i<(arr.size()-1)/2;i++)
        {
            if(arr[low]==arr[high])
            {
                low+=2;
                high+=2;
            }
            else if(arr[low]!=arr[high])
            {
                if(arr[low]!=arr[low-1])
                    return arr[low];
                // else 
                //     return arr[high];
            }
        }
            return -1;
    }
};


// 