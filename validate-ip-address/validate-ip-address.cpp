class Solution {
     string checkIPv6(string IP){
        int i = 0, j = 0, count = 0;
        while(j < IP.length()){
            if(IP[j] == ':'){
                count++;
                string s = IP.substr(i, j - i);
                if(s.length() < 1 or s.length() > 4)
                    return "Neither";
                i = j + 1;
                j = j + 1;
                if(count==7)
                    break;
            }
            else
                j = j + 1;
        }
        string s = IP.substr(i, IP.length() - j);
        
        if(s.length() == 0)
            return "Neither";
        if(s.length() < 1 or s.length() > 4)
                    return "Neither";
        return "IPv6";
    }
    
    string checkIPv4(string IP){
        int i = 0, j = 0, count = 0;
        while(j < IP.length()){
            if(IP[j] == '.'){
                count++;
                string s = IP.substr(i, j - i);
                if(s.length() == 0)
                    return "Neither";
                if(s[0] == '0' and s.length()!= 1)
                    return "Neither";
                if(stoi(s) > 255)
                    return "Neither";
                i = j + 1;
                j = j + 1;
                if(count==3)
                    break;
            }
            else
                j = j + 1;
        }
        string s = IP.substr(i, IP.length() - i);
        if(s.length() == 0)
            return "Neither";
        if(s[0] == '0' and s.length()!= 1)
                    return "Neither";
        if(stoi(s) > 255)
                    return "Neither";
        return "IPv4";
    }
public:
    string validIPAddress(string IP) {
        int dot = 0, colon = 0;
        for(int  i = 0; i < IP.length(); i++){
            if(IP[i] == '.')
                dot++;
            if(IP[i] == ':')
                colon++;
        }
        
        if(dot == 3 and colon == 0 and IP.length() <= 15){
            for(int i = 0; i < IP.length(); i++){
                if(isalpha(IP[i]))
                    return "Neither";
            }
            return checkIPv4(IP);
        }
        else if(colon == 7 and dot == 0){
            for(int i = 0; i < IP.length(); i++){
                if(IP[i] >= 'G' and IP[i] <= 'Z')
                    return "Neither";
                if(IP[i] >= 'g' and IP[i] <= 'z')
                    return "Neither";
            }
            return checkIPv6(IP);
        }
        else
            return "Neither";
    }
    
    
   
};