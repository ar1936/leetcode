class Solution {
    bool solve(vector<int>nums,int l,int r){
        vector<int>temp;
        for(int i=l;i<=r;i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(),temp.end());
        int d=temp[1]-temp[0];
        for(int i=1;i<temp.size();i++){
            if(d!=(temp[i]-temp[i-1]))
                return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=l.size();
        vector<bool>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=(solve(nums,l[i],r[i])==true?true:false);
        }
        return ans;
    }
};