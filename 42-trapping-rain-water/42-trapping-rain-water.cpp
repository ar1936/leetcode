class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int ans=0,n=height.size();
        vector<int>max_left(n),max_right(n);
        max_left[0]=height[0];
        for(int i=1;i<n;i++){
            max_left[i]=max(height[i],max_left[i-1]);
        }
        max_right.back()=height.back();
        for(int i=n-2;i>=0;i--){
            max_right[i]=max(max_right[i+1],height[i]);
        }
        for(int i=1;i<n-1;i++){
            ans+=min(max_left[i],max_right[i])-height[i];
        }
        return ans;
    }
};