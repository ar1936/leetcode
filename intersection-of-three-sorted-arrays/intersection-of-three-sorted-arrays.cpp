class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int,int>mp;
        vector<int>v;
        for(int i=0;i<arr1.size();i++)
            mp[arr1[i]]++;
        for(int i=0;i<arr2.size();i++)
            mp[arr2[i]]++;
        for(int i=0;i<arr3.size();i++)
        {
            mp[arr3[i]]++;
            if(mp[arr3[i]]==3)
                v.push_back(arr3[i]);
        }
        return v;
        
    }
};