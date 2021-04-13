class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int>s;
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.empty())
                mp[nums2[i]]=-1;
            else if(!s.empty()&&nums2[i]<s.top()){
                mp[nums2[i]]=s.top();
            }
            else if (!s.empty()&&nums2[i]>=s.top()){
                while(!s.empty()&&nums2[i]>=s.top())
                    s.pop();
            if(s.empty())
                mp[nums2[i]]=-1;
            else 
                mp[nums2[i]]=s.top();
                
            }
            s.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            nums1[i]=mp[nums1[i]];
        }
        return nums1;
    }
};