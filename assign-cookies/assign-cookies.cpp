// My try-> understanding question is a great technique to solve question


// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int count=0;
//         sort(s.begin(),s.end());
//         set<int>st;
//         for(int i=0;i<g.size();i++){
//             st.insert(g[i]);
//         }
//         g.clear();
//         for(auto x:st){
//             g.push_back(x);
//         }
//         for(int i=0;i<g.size();i++){
//             for(int j=0;j<s.size();j++){
//                 if(s[j]==g[i]){
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };




class Solution {
public:
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i])
                i++; // when the child get the cookie, foward child by 1
            j++;
        }
        return i;
    }
};