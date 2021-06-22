class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        // store {weight, server_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_server_pq;
        // store {end_time, server_index}, use long instead of int because the time maybe overflow
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> busy_server_pq;
        vector<int> ans(m);
        
        for (int i = 0; i < n; ++i) {
            free_server_pq.push({servers[i], i});
        }
        
        long time = 0;
        for (int i = 0; i < m; ++i) {
            time = max(static_cast<long>(i), time);
            if (free_server_pq.empty() && busy_server_pq.top().first > time) {
                time = busy_server_pq.top().first;
            }
            
            while (!busy_server_pq.empty() && busy_server_pq.top().first <= time) {
                auto &info = busy_server_pq.top();
                int server_idx = static_cast<int>(info.second);
                free_server_pq.push({servers[server_idx], server_idx});
                busy_server_pq.pop();
            }
            
            auto &info = free_server_pq.top();
            busy_server_pq.push({time + tasks[i], info.second});
            ans[i] = info.second;
            free_server_pq.pop();
        }
        
        return ans;
    } 
};