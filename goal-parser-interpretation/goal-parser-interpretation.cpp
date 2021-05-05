class Solution {
public:
    string interpret(string command) {
        string str;
        for(int i=0;i<command.size();i++){
            if(command[i]=='('&&command[i+1]==')')
            {
                str.push_back('o');
                i++;
            }
            else if(command[i]=='('&&command[i+1]=='a'){
                
                    str.push_back('a');
                    str.push_back('l');
                i+=3;
                    
                }
            else 
                str.push_back(command[i]);
            
        }
        return str;
    }
};