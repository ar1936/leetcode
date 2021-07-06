// class Solution {
//     vector<int> ans;
//     void merge(vector<int>&v,int l, int m, int r){
//         int count=0;
//         vector<int>temp(r-l+1);
//         int i=l,j=m+1,k=0;
//         while(i<=m&&j<=r){
//             if(v[i]<=v[j]){
//                 temp[k++]=v[i++];
                
//             count++;
                
//             }
//             else{
//                 temp[k++]=v[j++];
//             }
//         }
//         while(i<=m){
//             temp[k++]=v[i++];
            
//             count++;
//         }
//         while(j<=r){
//             temp[k++]=v[j++];
//         }
//         cout<<count<<" ";
//         for(int i=0;i<k;i++){
//             v[l+i]=temp[i];
//         }
//     }
//     void merge_sort(vector<int>&v,int l,int r){
//         if(l<r){
//             int mid=l+(r-l)/2;
//             merge_sort(v,0,mid);
//             merge_sort(v,mid+1,r);
//             merge(v,l,mid,r);
//         }
//     }
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         merge_sort(nums,0,nums.size()-1);
//         // return ans;
//         return nums;
//     }
// };



class Solution {
public:
    int arr[100000]; //used to store the result using indices
    vector<int> countSmaller(vector<int>& nums) {
        //we store the vector of pairs
        
        //why we use pair , since we need to know the index of the element in the original array 
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums.size();i++)
        {
            pairs.push_back({nums[i],i});
        }
        
        mergeSort(pairs,0,nums.size()-1);
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            res[i]=arr[i];
        }
        return res;
    }
    void mergeSort(vector<pair<int,int>>& pairs,int low,int high)
    {
        int mid=(low+high)/2;
        if(low<high)
        {
            //need to split them
            mergeSort(pairs,low,mid);
            mergeSort(pairs,mid+1,high);
            //merge them and calculate the result for every element
            merge(pairs,low,mid+1,high);
        }
    }
    
    void merge(vector<pair<int,int>>& pairs,int low,int mid,int high){
        //mid is the starting element for the second array
        int i=low;
        int j=mid;
        int count=0; //the number of elements smaller in the arr from mid to high
        vector<pair<int,int>> temp(high-low+1);
        int k=0;
        while(i<=mid-1 && j<=high)
        {
            if(pairs[i].first<=pairs[j].first)
            {
                arr[pairs[i].second]+=count; //add the number of smaller elements
                temp[k++]={pairs[i++]};
            }
            else{
                //a smaller element found
                count++;
                temp[k++]={pairs[j++]};
            }
        }
        //add the remaining first array element if left any
        while(i<=mid-1)
        {
            arr[pairs[i].second]+=count; //add the number of smaller elements
            temp[k++]={pairs[i++]}; 
        }
        //add the remaining second array elements if left any
        while(j<=high)
        {
            temp[k++]={pairs[j++]};
        }
        //change the pairs to make it in sorted order 
        for(int i=0;i<k;i++)
        {
            pairs[low++]=temp[i];
        }
    }
};