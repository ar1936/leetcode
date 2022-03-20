class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=INT_MAX,j=6,temp=0,up_mx_fre=0,up_mx_fre_ind=0,down_mx_fre=0,down_mx_fre_ind=0;
        vector<int>up(6),down(6);
        for(auto x:tops){
            up[x-1]++;
        }
        for(auto x:bottoms){
            down[x-1]++;
        }
        for(int i=0;i<6;i++){
            if(up_mx_fre<=up[i]){
                up_mx_fre=up[i];
                up_mx_fre_ind=(i+1);
            }
            if(down_mx_fre<=up[i]){
                down_mx_fre=down[i];
                down_mx_fre_ind=(i+1);
            }
        }
        if(up_mx_fre>down_mx_fre){
            j=up_mx_fre_ind;
        }
        else{
            j=down_mx_fre_ind;
        }
        for(int i=0;i<tops.size();i++){
            
            if(tops[i]==j){
            }
            else if(bottoms[i]==j){
                temp++;
            }
            else{
                temp=0;
                j++;
                break;
            }
            if(i==tops.size()-1) {
                // cout<<temp<<" ";
                ans=min(temp,ans);
                j++;
                break;
            }
        }
        if(up_mx_fre>down_mx_fre){
            j=up_mx_fre_ind;
        }
        else{
            j=down_mx_fre_ind;
        }
        cout<<j<<" ";
        temp=0;
        for(int i=0;i<tops.size();i++){
            if(bottoms[i]==j){
            }
            else if(tops[i]==j){
                temp++;
            }
            else{
                temp=0;
                j++;
                break;
            }
            if(i==tops.size()-1) {
                // cout<<temp<<" ";
                ans=min(temp,ans);
                j++;
                break;
            }
        }
        if(ans==INT_MAX)
            return  -1;
        return ans;
    }
};