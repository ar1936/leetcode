class Solution {
    vector<int>parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        
        sort(logs.begin(), logs.end());
        
        parent.resize(N, 0);
        for (int i = 0; i < N; i++)
            parent[i] = i;
        
        for (int i = 0; i < logs.size(); i++) {
            int x = find(logs[i][1]);
            int y = find(logs[i][2]);
            if (x != y) {
                N--;
                if (N == 1) return logs[i][0];
                parent[y] = x;
            }
        }
        
        return -1;
    }
};