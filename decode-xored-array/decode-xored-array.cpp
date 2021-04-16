class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
	for (int &n : encoded) {
		swap(n, first);
		first ^= n;
	}
	encoded.push_back(first);
	return encoded;
}
};