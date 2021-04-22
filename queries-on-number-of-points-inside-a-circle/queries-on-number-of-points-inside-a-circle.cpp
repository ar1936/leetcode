class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int x1,x2,y1,y2,r;
        float dis=0;
        int count=0;
        vector<int>v(queries.size());
        for(int i=0;i<queries.size();i++){
            x1=queries[i][0];
            y1=queries[i][1];
            r=queries[i][2];
            count=0;
            for(int j=0;j<points.size();j++){
                x2=points[j][0];
                y2=points[j][1];
                dis=float(sqrt(pow(abs(x2-x1),2)+pow(abs(y2-y1),2)));
                    if(dis<=r)
                        count++;
            }
            v[i]=count;
        }
        return v;
    }
};