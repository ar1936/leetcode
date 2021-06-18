// class Solution {
// public:
//     int minSwaps(string s) {
//         int n=s.size(),count1=0,count0=0,ans=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='0')
//                 count0++;
//             else 
//                 count1++;
//         }
//         string temp="";
//         if(n%2==0){
//             for(int i=0;i<n/2;i++){
//                 temp+="01";
//             }
//             if(count0!=count1)
//                 return -1;
//         }
//         else {
//             for(int i=0;i<n/2;i++){
//                 temp+="01";
//             }
//             temp+='0';
//             if(abs(count1-count0)>1)
//                 return -1;
//         }
        
//         for(int i=0;i<n;i++){
//             if(s[i]!=temp[i])
//                 ans++;
//         }
        
//         return (min(ans,n-ans)%2==0?min(ans,n-ans)/2:(min(ans,n-ans)+1)/2);
//     }
// };


class Solution {
public:
        int minSwaps(string s) {
            int cnt0 = count(begin(s), end(s), '0'), cnt1 = s.size() - cnt0, miss0 = 0, miss1 = 0;
            if (abs(cnt0 - cnt1) > 1)
                return -1;
            for (int i = 0; i < s.size(); i += 2) {
                // miss0 += s[i] != '0';
                // miss1 += s[i] != '1';
                if(s[i]!='0')
                    miss0++;
                else
                    miss1++;
            }
            return cnt0 == cnt1 ? min(miss0, miss1) : cnt0 > cnt1 ? miss0 : miss1;
        }
};