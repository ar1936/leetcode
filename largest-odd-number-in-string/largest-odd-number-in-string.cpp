class Solution {
public:
    string largestOddNumber(string num) {
        
        
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'a')%2!=0){
                num.erase(num.begin()+i);
            }
            else
                break;
        }
        return num;
    }
};