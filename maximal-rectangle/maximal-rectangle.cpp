class Solution {
public:
        int largestRectangleArea(vector<int>& heights) {
        vector<int>nsr,nsl;
        stack<pair<int,int> >s;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(s.empty())
                nsl.push_back(-1);
            else if(!s.empty()&&s.top().first<heights[i])
                nsl.push_back(s.top().second);
            else if (!s.empty()&&s.top().first>=heights[i]){
                while(!s.empty()&&s.top().first>=heights[i])
                    s.pop();
                    if(s.empty())
                        nsl.push_back(-1);
                    else 
                        nsl.push_back(s.top().second);
                }
                s.push({heights[i],i});
            }
        
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--){
            if(s.empty())
                nsr.push_back(n);
            else if(!s.empty()&&s.top().first<heights[i])
                nsr.push_back(s.top().second);
            else if (!s.empty()&&s.top().first>=heights[i]){
                while(!s.empty()&&s.top().first>=heights[i])
                    s.pop();
                if(s.empty())
                    nsr.push_back(n);
                else 
                    nsr.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        int m=INT_MIN;
        reverse(nsr.begin(),nsr.end());
        for(int i=0;i<n;i++){
            m=max(m,(nsr[i]-nsl[i]-1)*heights[i]);
        }        
        return m;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[i].size();j++)
        //         matrix[i][j]=matrix[i][j]-'0';
        //     }
         
             vector<int>v;
        for(int j=0;j<matrix[0].size();j++){
            matrix[0][j]=matrix[0][j]-'0';
            v.push_back(matrix[0][j]);
        }
        int m=largestRectangleArea(v);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                matrix[i][j]=matrix[i][j]-'0';
                if(matrix[i][j]==0)
                    v[j]=0;
                else
                    v[j]=v[j]+matrix[i][j];
            }
            m=max(m,largestRectangleArea(v));
        }
        return m;
    }
   
        
};