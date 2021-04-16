class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>v(n),v1(n);
        for(int i=0;i<n;i++){
            v[i]=boxes[i]-'0';
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(v[j]==1)
                    sum+=abs(j-i);
                else
                    sum+=0;
            }
            v1[i]=sum;
        }
        return  v1;
    }
};