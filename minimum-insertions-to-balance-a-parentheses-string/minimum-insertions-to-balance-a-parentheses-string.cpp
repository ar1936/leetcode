class Solution {
public:
      int minInsertions(string s) {
        int res = 0, right = 0;
        for (char &c: s) {
            if (c == '(') {
                if (right % 2 > 0) {
                    right--;
                    res++;
                }
                right += 2;
            } else {
                right--;
                if (right < 0) {
                    right += 2;
                    res++;
                }
            }
        }
        return right + res;
    }
};

// //         ( ( ) ) )
// // sum_o   1 2 2 2 2 
// // sum_c   0 0 1 2 3 
// // ans  = 2*sum_o-sum_c;

// //            ( ) )
// // sum_o      1 1 1 
// // sum_c      0 1 2 
// // ans =     2*sum_o -sum_c;



//            ) ) ( ) ) (
// sum_o      0 0 1 0 0 2
// sum_c      1 2 2 3 4 4 
               
// if(sum_c!=0&&sum_o==0)
// ans =     2*sum_o -sum_c;