class Solution {
public:
    
    // Function to find the total number
    // hours needed to cover all the distances
    // with speed K
    double countTotalHours(vector<int> &arr, int N, int K) {
        
        // Stores the total hours needed
        double ans = 0.0;

        // Find the sum of ceil values of
        // the first (N - 1) distances/K
        for(int i = 0; i < N - 1; i++) {
            ans += ceil((double)(1.0*arr[i])/K);
        }
        
        ans += (1.0*arr[N - 1])/K;
        
        // Return the total hours
        return ans;
        
    }
    
    // Driver Function
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int N = dist.size();

        // Stores the resultant minimum speed value
        int ans = INT_MAX;

        // Stores the minimum and the maximum ranges
        // of speed that can be possible
        int low = 1;
        int high = 10000000;

        // Perform the Binary Search for the range
        // [low, high]
        while(low <= high) {
            
            // Find the middle speed value
            int mid = low + (high - low)/2;

            // Function to find the total number
            // hours needed to cover all the distances
            // according to the given criteria
            double count = countTotalHours(dist, N, mid);

            // If the count of hours is less than
            // the given hours then mid can be the
            // one of the possible values of hours

            // Now, our range shrinks to
            // [low, mid]
            if(count <= hour) {

                // Update the minimum
                // answer value of hour
                ans = min(ans, mid);
                high = mid - 1;
            }
            
            // If the count of hours is greater
            // than the given hours then all values
            // before mid can't be the possible
            //  values of hours

            // Now, our range shrinks to
            // [mid + 1, high]
            
            else {
                low = mid + 1;
            }
        }
        
        // If the minimum speed doesn't exists
        // then return -1. Otherwise, return ans
        return (ans == INT_MAX ? -1 : ans);
    }
};