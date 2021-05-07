// class Solution {
// public:
//     bool checkOnesSegment(string s) {
//         int count1=0,count2=0,mx1=0,mx2=0;
//         bool flag=true;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='1')
//             {
//                 count1++;
//                 mx1=max(count1,mx1);
//             }
//             else
//                 flag =false;
//             if(s[i]=='0')
//             {
//                 count2++;
//                 mx2=max(count2,mx2);
//             }
//             else
//                 count2=0;
//         }
//         return flag;
//     }
// };


class Solution {
public:

    bool checkOnesSegment(string s) {
        return -1 == s.find("01");
    }
};