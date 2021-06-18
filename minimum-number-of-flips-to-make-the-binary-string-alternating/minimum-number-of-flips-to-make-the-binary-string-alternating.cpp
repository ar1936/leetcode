// class Solution {
// public:
//     int minFlips(string s) {
//         int ans=0,n=s.size();
//         string temp="";
//         if(n%2==0){
//             for(int i=0;i<n/2;i++){
//                 temp+="01";
//             }
//         }
//         else{
//             for(int i=0;i<n/2;i++){
//                 temp+="01";
//             }
//             temp.push_back('0');
//         }
//         for(int i=0;i<n;i++){
//             if(temp[i]!=s[i])
//                 ans++;
//         }
    
//         return min(ans, n-ans);
            
//     }
// };


// using sliding window concept 

class Solution {
public:
    int minFlips(string s) {
        
        int n=s.size();
        
        // Make size of given string double so we can apply sliding window concept here. 
        s=s+s;
        
        //now create a temp string which is same as given in question
        string temp="";
        for(int i=0;i<n;i++){
            temp+="01";
        }
        vector<int>v(n);
        int count_diff=0;
        // now our sliding window concept start
        
        for(int i=0;i<n;i++){
            if(temp[i]!=s[i])
                count_diff++;
        }
        v[0]=min(n-count_diff,count_diff);
        
        for(int i=n;i<s.size();i++){
            if(temp[i-n]!=s[i-n])
                count_diff--;
            if(temp[i]!=s[i])
                count_diff++;
            v[i-n]=min(n-count_diff,count_diff);
        }
        sort(v.begin(),v.end());
;        return v[0];
    }
};