class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        multiset<int>st;
        for(auto x:nums1){
            st.insert(x);
        }
        for(auto x:nums2){
            st.insert(x);
        }
        for(auto x:st){
            temp.push_back(x);
        }
        int n=temp.size();
        if(n%2==0){
            return double(double (temp[n/2-1])+ double (temp[n/2]))/2;
        }
        return double(temp[n/2]);
    }
};