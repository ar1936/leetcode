// class Solution {
// public:
//     int minTimeToType(string word) {
//         map<char,int>mp;
//         for(int i='a';i<='z';i++){
//             if(i+1-'a'<=13)
//                 mp[i]=(i-'a'+1);
//             else
//                 mp[i]=26-(i-'a');
//         }
//         int ans1=0,prev=0;
//         for(int i=0;i<word.size();i++){
//             ans1+=abs(prev-mp[word[i]]);
//             prev=mp[word[i]];
//         }
//         for(auto x:mp){
//             cout<<x.first<<" "<<x.second<<"\n ";
//         }
//         return ans1;
//     }
// };

class Solution {
public:
    int minTimeToType(string word) {
        int seconds = word.length(); //It takes 1 second to print each character
        char prev   = 'a';           //pointer is at 'a' in the beginning
        
        for(const char &curr : word) {
            
            int curr_to_prev = curr-prev;
            int prev_to_curr = prev-curr;
            
            if(curr_to_prev < 0) curr_to_prev += 26;
            
            if(prev_to_curr < 0) prev_to_curr += 26;
            
            seconds += min(curr_to_prev, prev_to_curr);
            prev     = curr;
        }
        return seconds;
    }
};