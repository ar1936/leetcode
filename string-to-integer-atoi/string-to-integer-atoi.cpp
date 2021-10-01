class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0)
            return 0;
        bool only_space=false;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]!=' ')
                only_space=true;
        }
        if(!only_space)
            return 0;
        long int res = 0;
        int size = str.size();
        int i, flag;

        i=0;flag = 1;
        i = str.find_first_not_of(' ');
        if(str[i]=='-'){
            flag = -1;
            i++;
        }
        else if(str[i]=='+'){
            i++;
        }
        for(; isdigit(str[i])&&res<=INT_MAX&&i<size; i++)
            res = res*10+(int)(str[i]-'0');
        if(flag*res>INT_MAX)
            return  INT_MAX;
        if(flag*res< INT_MIN)
            return  INT_MIN;
        return flag*res;
    }
};