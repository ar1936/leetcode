// It is necessary to sort by score when there's a tie in age to guarantee priority for "stronger peers" ; otherwise, "stronger peers" may appear after "weaker peers", and thus cause fault.


// Idea is to first sort the players by their age so that we don't have to always check both the scores and the age to see whether these two players can be in the same team.

// We sort first in the descending order of the ages.
// Now we know that for any player i, we can choose any player from 0 to i-1 as long as that player has higher score than this i-th player.

// dp[i] stores the maximum score that can be obtained when i-th player is included and all other players are between indices 0 and i-1.
// Once we get the answer for all indices, we can simply find the max and that will be the answer.

// // Code would help understand this even more easily.





class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        int n = scores.size();
        for (int i=0; i<n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end(), greater<>());
        
        int ans = 0;
        vector<int> dp(n);
        for (int i=0; i<n; i++) {
            int score = players[i].second;
            dp[i] = score;
            for (int j=0; j<i; j++) {
                if (players[j].second >= players[i].second) { // age of j is certainly >= i, so only important part to check 
													          //  before we add i and j in the same team is the score.
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};