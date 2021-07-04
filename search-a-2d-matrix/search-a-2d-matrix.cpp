class Solution {
    bool b_s(vector<int>v,int target){
        int lo=0,hi=v.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]==target)
                return true;
            else if(v[mid]>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(b_s(matrix[i],target))
                return true;
        }
        return false;
    }
};