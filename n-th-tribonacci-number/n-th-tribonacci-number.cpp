class Solution {
public:
    int tribonacci(int n) {
        int arr[38];
        memset(arr,0,sizeof(arr));
        arr[0]=0;
        arr[1]=1;
        arr[2]=1;
        if(n<=2)
            return arr[n];
        for(int i=3;i<=n;i++)
        {
            arr[i]=arr[i-3]+arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};