class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string,int>type,color,name;
        for(int i=0;i<items.size();i++){
            
                if(ruleKey=="type")
                    type[items[i][0]]++;
                if(ruleKey=="color")
                    color[items[i][1]]++;
                if(ruleKey=="name")
                    name[items[i][2]]++;
        }
        if(ruleKey=="type")
            return type[ruleValue];
        if(ruleKey=="color")
             return color[ruleValue];
        if(ruleKey=="name")
            return name[ruleValue];
        return 1;
    }
};