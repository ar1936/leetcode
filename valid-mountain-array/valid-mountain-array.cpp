class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // Edge case:
        if (arr.size() <= 1)
            return false;
        
        int i = 0;
        
        // Go while there's a hill up, untill we reach peak:
        while (i < arr.size()-1 && arr[i] < arr[i+1])
            i++;
           
        // Peak can't be the first or last:
        if (i == 0 || i == arr.size()-1)
            return false;
        
        // Walk downhill:
        while (i < arr.size()-1 && arr[i] > arr[i+1])
            i++;
        
        // If there's a larger number after we started walking down, this will be false:
        return i == arr.size()-1;
    }
};