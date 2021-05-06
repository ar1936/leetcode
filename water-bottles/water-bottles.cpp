// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//         int count=0,left,vac=0,total=numBottles;
//         while(numBottles){
//             count+=numBottles;
//             // cout<<count<<" ";
//             left=total-(numExchange*vac);
//             vac=total/numExchange+left;
//             if(vac==0)
//                 break;
            
//             numBottles=vac;
//             total=vac+left;
//         }
//         return count;
//     }
// };


class Solution {
public:
int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        while(numBottles >= numExchange)
        {
            int remainingBottles = numBottles%numExchange;
            numBottles /= numExchange;
            count += numBottles;
            numBottles += remainingBottles;
        }
        return count;
    }
};