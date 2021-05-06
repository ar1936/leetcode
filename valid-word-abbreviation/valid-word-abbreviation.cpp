//My try;



// class Solution {
// public:
//     bool validWordAbbreviation(string word, string abbr) {
//        int count=0;
//         if(abbr.size()==1){
//             if(abbr[0]>='0'&&abbr[0]<='9')
//                 count=abbr[0]-'0';
//             else 
//                 count++;
//             return count==word.size();
//         }
//         for(int i=0;i<abbr.size();i++){
//             if((abbr[i]>='0'&&abbr[i]<='9')&&(abbr[i+1]>='0'&&abbr[i+1]<='9'))
//             {
//                 count=count+10*(abbr[i]-'0')+(abbr[i+1]-'0');
//                 i+=1;
//             }
//             else if(abbr[i]>='0'&&abbr[i]<='9')
//                 count=count+(abbr[i]-'0');
//             else if (abbr[i]>='a'&&abbr[i]<='z')
//                 count++;
//         }
//         return count==word.size();
//     }
// };


class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') 
                    return false;
                int val = 0;
                while (j < abbr.size() && isdigit(abbr[j])) 
                    val = val * 10 + (abbr[j++] - '0');
                i += val;
            }
            else if (word[i++] != abbr[j++]) 
                return false;
        }
        return i == word.size() && j == abbr.size();
    }
};




