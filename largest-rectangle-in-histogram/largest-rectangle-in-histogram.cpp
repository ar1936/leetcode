class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nsr,nsl;
        stack<pair<int,int> >s,st;
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
        
        // while(!s.empty())
        //     s.pop();
        for(int i=n-1;i>=0;i--){
            if(st.empty())
                nsr.push_back(n);
            else if(!st.empty()&&st.top().first<heights[i])
                nsr.push_back(st.top().second);
            else if (!st.empty()&&st.top().first>=heights[i]){
                while(!st.empty()&&st.top().first>=heights[i])
                    st.pop();
                if(st.empty())
                    nsr.push_back(n);
                else 
                    nsr.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        int m=INT_MIN;
        reverse(nsr.begin(),nsr.end());
        for(int i=0;i<n;i++){
            m=max(m,(nsr[i]-nsl[i]-1)*heights[i]);
        }        
        return m;
    }
};