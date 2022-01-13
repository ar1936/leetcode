class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>digits;
        vector<pair<string,string>>mp;
        bool flag=false;
        for(auto x:logs){
            string first_part="",second_part="";
            for(int i=0;i<x.size();i++){
                if(x.back()>='a'&&x.back()<='z'){
                    if(flag==false && x[i]!=' '){
                        first_part+=x[i];
                    }
                    else if(flag==false && x[i]==' '){
                        flag=true;
                    }
                    if(flag ){
                        second_part+=x[i];
                    }
                }
                else{
                    break;
                }
            }
            if(flag){
                mp.push_back({second_part,x});
            }
            else{
                digits.push_back(x);
            }
            flag=false;
        }
        sort(mp.begin(),mp.end());
        int i=0;
        for(auto x:mp){
            logs[i]=x.second;
            i++;
            cout<<x.second<<"\n";
        }
        for(auto x:digits){
            logs[i]=x;
            i++;
            cout<<x<<"\n";
        }
        return logs;
    }
};