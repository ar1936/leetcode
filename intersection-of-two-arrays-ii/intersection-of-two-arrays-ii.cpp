// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         set<int>s;
//         vector<int>v;
//         // if(nums.size==1)
            
// //         if(nums1.size()>nums2.size())
// //         {
// //                 for(int i=0;i<nums1.size();i++)
// //                     {
// //                         s.insert(nums1[i]);
// //                     }
// //         }
// //          if(nums1.size()<=nums2.size())
// //         {
// //                 for(int i=0;i<nums2.size();i++)
// //                     {
// //                         s.insert(nums2[i]);
// //                     }
// //         }
// //         if(nums1.size()>nums2.size()){
// //             for(int i=0;i<nums2.size();i++)
// //             {
// //                 if(s.find(nums2[i])!=s.end())
// //                     v.push_back(nums2[i]);
// //             }
// //         }
// //         if(nums1.size()<=nums2.size()){
// //             for(int i=0;i<nums1.size();i++)
// //             {
// //                 if(s.find(nums1[i])!=s.end())
// //                     v.push_back(nums1[i]);
// //             }
// //         }
        
        
//         map<int,int>mp1,mp2;
//         for(int i=0;i<nums1.size();i++)
//             mp1[nums1[i]]++;
//         for(int i=0;i<nums2.size();i++)
//             mp2[nums2[i]]++;
//         for(int i=0;i<nums1;i++)
//         {
//             if(mp1[nums1[i]]==mp2[nums1[i]])
//             {
//                 while(mp1[nums1[i]]--)
//                     v.push_back(nums1[i]);
//             }
//             if(mp1[nums1[i]]<mp)
//         }
//         return v;
//     }
// };



class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(auto i : nums1)
        {
            if(m.find(i) == m.end())
                m.insert(make_pair(i, 1));
            else
                m[i]++;
        }
        vector<int> res{};
        for(auto i : nums2)
        {
            if(m.find(i) != m.end() && m[i] != 0)
            {
                res.push_back(i);
                m[i]--;
            }
        }
        return res;
    }
};