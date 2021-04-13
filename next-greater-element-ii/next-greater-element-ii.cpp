class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int>s;
        vector <int>v;
        int n=nums.size();
        // nums.resize(n);
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
        if(s.empty())
            v.push_back(-1);
        else if(!s.empty()&&nums[i]<s.top())
            v.push_back(s.top());
        else if (!s.empty()&&nums[i]>=s.top()){
            while(!s.empty()&&nums[i]>=s.top())
                s.pop();
                if(s.empty())
                    v.push_back(-1);
                else 
                    v.push_back(s.top());
            }
        
        
            s.push(nums[i]);
        
        }
        reverse(v.begin(),v.end());
        // for(int i=0;i<n;i++){
        //     v.pop_back();
        // }
        v.resize(n);
        return v;
    }
};