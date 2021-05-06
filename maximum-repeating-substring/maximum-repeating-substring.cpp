// class Solution {
// public:
//     int maxRepeating(string sequence, string word) {
//         int count=0;
//         int n=word.size();
//         if(sequence.size()==n){
//             for(int i=0;i<n;i++){
//                 if(sequence[i]!=word[i])
//                     return 0;
                
//             }
//             return 1;
//         }
//         else
//         {
//             for(int i=0;i<sequence.size()-n;i++){
//             if(sequence.substr(i,n)==word)
//                 count++;
//             }
//         }
//         return count;
//     }
// };




class Solution {
public:
	int maxRepeating(string sequence, string word) {
		int k = 0;
		string temp = word;

		while(sequence.find(temp) != -1){
			temp += word;
			k++;
		}

		return k;
	}
};