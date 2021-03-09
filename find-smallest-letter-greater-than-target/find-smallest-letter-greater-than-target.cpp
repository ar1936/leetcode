class Solution {
public:
    char nextGreatestLetter(vector<char>& chars, char target) {
      if(target>chars[chars.size()-1]||target<chars[0]) return chars[0];
        int low = 0;
        int high = chars.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(chars[mid]>target)high= mid-1;
            else   low = mid+1;
        }
        return chars[low%chars.size()];
    }
};