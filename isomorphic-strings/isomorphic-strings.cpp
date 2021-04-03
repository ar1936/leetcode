class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> m;
		set<char> st;
		for(int i = 0; i < s.size(); i++){
			if(m.find(s[i]) != m.end()){
				if(m[s[i]] != t[i]){
					return false;
				}
			}
			else{
				if(st.count(t[i]) > 0){
					return false;
				}
				m[s[i]] = t[i];
				st.insert(t[i]);
			}
		}
		return true;
	}
};