// MY try
// wrong test case -> "a  "

// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int count=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]!=' ')
//                 count++;
//             else
//                 count=0;

//         }
//         return count;
//     }
// };



// Well, the basic idea is very simple. Start from the tail of s and move backwards to find the first non-space character. Then from this character, move backwards and count the number of non-space characters until we pass over the head of s or meet a space character. The count will then be the length of the last word.

class Solution {
public:
    int lengthOfLastWord(string s) { 
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') 
            tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};

