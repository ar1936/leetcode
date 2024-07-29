class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=0;
        for(int i=0;i<rating.size();++i)
        {
            for(int j=i+1;j<rating.size();++j)
            {
                for(int k=j+1;k<rating.size();++k)
                {
                    if((rating[i]<rating[j])&&(rating[j]<rating[k])||(rating[i]>rating[j])&&(rating[j]>rating[k]))
                    {
                        ++n;
                    }                                                       
                }
            }
            
        }
        return n;
        
    }
};
// class Solution {
// public:
//     int numTeams(vector<int>& rating) 
//     {
//         int team=0;
//         for(int i=0;i<rating.size();++i)
//         {
//             for(int j=i+1;j<rating.size();++j)
//             {
//                 for(int k=j+1;k<rating.size();++k)
//                 {
//                     if((rating[i]>rating[j] && rating[j]>rating[k]) || (rating[i]<rating[j] && rating[j]<rating[k]))
//                     {
//                         ++team;
//                     }
//                 }
//             }
//         }
//         return team;
//     }
// };