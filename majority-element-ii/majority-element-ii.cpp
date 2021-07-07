class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // support variables
        int cand1, vote1 = 0, cand2, vote2 = 0, lmt = nums.size() / 3;
        // looking for the 2 most frequent items
        for (int n: nums) {
            if (n == cand1) vote1++;
            else if (n == cand2) vote2++;
            else if (!vote1) {
                cand1 = n;
                vote1++;
            }
            else if (!vote2) {
                cand2 = n;
                vote2++;
            }
            else {
                vote1--;
                vote2--;
            }
        }
        // checking the actual frequency of the 2 most common items
        vote1 = 0;
        vote2 = 0;
        for (int n: nums) {
            if (n == cand1) vote1++;
            if (n == cand2) vote2++;
        }
        // making sure cand1 has more votes
        if (vote1 < vote2) {
            swap(cand1, cand2);
            swap(vote1, vote2);
        }
        vector<int>ans;
        if(vote1>lmt)
            ans.push_back(cand1);
        if(vote2>lmt)
            ans.push_back(cand2);
        return ans;
        
        // return vote1 <= lmt ? vector<int>{} : vote2 <=lmt ? vector<int>{cand1} : vector<int>{cand1, cand2};
        return {};
    }
};


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int len = nums.size();
//         vector<int> v;
//         if(len == 0) return v;
        
//         for(int i = 0; i < 10; i++){
//             int c = 0;
//             int x = nums[rand() % len];
//             for(int j = 0; j < len; j++)
//                 if(x == nums[j])
//                     c++;
            
//             if(c > len / 3){
//                 if (find(v.begin(), v.end(), x) == v.end())
//                     v.push_back(x);
//             }
//         }
        
//         return v;
//     }
// };