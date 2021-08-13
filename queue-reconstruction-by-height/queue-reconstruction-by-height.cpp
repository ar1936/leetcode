class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){           // if height value is the same, then sort by k in raising powers
            return a[1] < b[1];
        }
        else{
            return a[0] > b[0];  // sort by height in descending powers
        }
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
		// after sort the example we get this vector:  [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
        vector<vector<int>> res;
        for(auto x:people){                     // insert the biggest height people first and insert in the k-th position
            res.insert(res.begin()+x[1],x);    // insert method: (position, value)
        }
        return res;
    }
};