//mY try 

// class Solution {
// public:
//     bool buddyStrings(string a, string b) {
//         if(a.size()!=b.size())
//             return false;
//         if(palindrome(a,b))
//             return true;
//         int count=0;
//         for(int i=0;i<a.size();i++){
//             if(a[i]!=b[i])
//                 count++;
            
//         }
//         if(count>2||count==0)
//             return false;
//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());
//         return a==b;
//     }
// };






class Solution {
public:
bool buddyStrings(string A, string B) {
        // Same length
        int len_A = A.size(), len_B = B.size();
        if (len_A != len_B) return false;
        
        // Repeat: same string, A needs repeated char, like "aab" "aab"
        unordered_set<char>s;
        for(int i=0;i<A.size();i++)
        {
            s.insert(A[i]);
        }
        int numChar_A=s.size(); 
    
        if (A == B && numChar_A < len_B) 
            return true;
        
        // Swap: There should be only two to change
        vector<int> index_diff;
                        
        for (int i = 0; i < len_A; i++) {
          if (A[i] != B[i]) 
              index_diff.push_back(i);
          if (index_diff.size() > 2) 
              return false;
        } 
        
        return (index_diff.size() == 2 &&A[index_diff[0]] == B[index_diff[1]] &&A[index_diff[1]] == B[index_diff[0]]);        
    }
};