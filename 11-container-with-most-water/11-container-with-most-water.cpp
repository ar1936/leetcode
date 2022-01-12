class Solution {
public:
    int maxArea1(vector<int>& height) {
        int ans=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                ans=max(ans,min(height[i],height[j])*(j-i));
            }
        }
        return ans;
    }

    int maxArea(vector<int>& height) {
        int ans=0,l=0,r=height.size()-1;
        while(l<r){
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};

