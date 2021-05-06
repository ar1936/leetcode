//My try 


// class Solution {
// public:
//     int countSegments(string s) {
//         int count =1;
//         if(s.empty())
//             return 0;
//         for(int i=1;i<s.size();i++){
//             if(s[i]==' '&&s[i-1]==' ')
//             {
//                 s.erase(s.begin()+i);
//                 s.erase(s.begin()+i-1);
//                 i--;
//                 // i--;
//             }
//         }
//          if(s.size()<=1&&s[0]==' ')
//             return 0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]==' ')
//                 count++;
//         }
      
//         return count;
//     }
// };


class Solution {
public:
    int countSegments(string s) {
       int n = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] != ' ')
                n++;
            while(i < s.size() && s[i] != ' ')
                i++;
        }
        return n;
    }
};





