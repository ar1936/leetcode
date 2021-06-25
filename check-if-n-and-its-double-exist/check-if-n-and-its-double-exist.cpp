class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int count_0=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)
            count_0++;
        }
        if(count_0>1)
            return true;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0)
                if(binary_search(arr.begin(),arr.end(),2*arr[i]))
                    return true;
        }   
        return false;
    }
};