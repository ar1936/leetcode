class Solution {
public:
    map<int, int> memo;

    int recursiveWithMemo(int index, string& str) {
        // Have we already seen this substring?
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length()) {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str[index] == '0') {
            return 0;
        }

        if (index == str.length() - 1) {
            return 1;
        }

        int ans = recursiveWithMemo(index + 1, str);
        if (stoi(str.substr(index, 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        memo[index] = ans;

        return ans;
    }

    int numDecodings(string s) {
        return recursiveWithMemo(0, s);
    }
};