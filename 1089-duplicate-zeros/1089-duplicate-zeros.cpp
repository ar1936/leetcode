 class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> queue;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0){
                queue.push(0);
                queue.push(0);
            }
            else{
                queue.push(arr[i]);
            }
            int first = queue.front();
                arr[i]= first;
        }
        int i=0;
        while(n--){
            arr[i]=queue.front();
            queue.pop();
            i++;
        }
    }
};