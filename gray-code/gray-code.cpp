class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        // Keeps track of the numbers present in the current sequence.
        unordered_set<int> isPresent;
        // All Gray code sequence starts with 0
        isPresent.insert(0);
        grayCodeHelper(result, n, isPresent);
        return result;
    }

private :
    bool grayCodeHelper(vector<int> &result, int n, unordered_set<int> &isPresent) {
        if (result.size() == (1 << n)) return true;

        int current = result[result.size() - 1];
        for (int i = 0; i < n; i++) {
            int next = current ^ (1 << i);
            if (isPresent.find(next) == isPresent.end()) {
                isPresent.insert(next);
                result.push_back(next);
                // If valid sequence found no need to search any further
                if (grayCodeHelper(result, n, isPresent)) return true;
                // If no valid sequence found delete the last added number and continue the search.
                isPresent.erase(next);
                result.pop_back();
            }
        }
        return false;
    }
};