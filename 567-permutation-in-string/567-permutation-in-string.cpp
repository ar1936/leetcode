// class Solution {
//     bool check(string s1, string s2){
//         string temp1=s1,temp2=s2;
//         sort(temp1.begin(),temp1.end());
//         sort(temp2.begin(),temp2.end());
//         return temp1==temp2;
//     }
// public:
//     bool checkInclusion(string s1, string s2) {
//         int k=s1.size(),n=s2.size();
//         if(k>n)
//             return false;
//         priority_queue<char>pq1.
//         string str="";
//         for(int i=0;i<k;i++){
//             str+=s2[i];
//         }
//         cout<<str<<"\n";
//         if(check(str,s1))
//             return true;
//         for(int i=k;i<n;i++){
//             str.erase(0,1);
//             str+=(s2[i]);
//             cout<<str<<"\n";
//             if(check(str,s1))
//                 return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map[26] = {0};
        for(char c : s1) map[c - 'a']++;
        int j = 0, i = 0, count_chars = s1.size();
        while(j < s2.size()){
            if(map[s2.at(j++) - 'a']-- > 0)
                count_chars--;
            if(count_chars == 0) return true;
            if(j - i == s1.size() && map[s2.at(i++) - 'a']++ >= 0)
                count_chars++;
        }
        return false;
    }
};