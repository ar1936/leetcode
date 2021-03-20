class Solution {
public:
  int knightDialer(int n) {
    unsigned int arr[9] = {1,1,1,1,1,1,1,1,1};
    if(n==1) return 10;
    unsigned int mod = 1000000007;
    
    while(--n){
      unsigned int narr[9];
      narr[0] = (arr[4] + arr[5])%mod;
      narr[1] = (arr[7] + arr[5])%mod;
      narr[2] = (arr[6] + arr[8])%mod;
      narr[3] = (arr[4] + arr[7])%mod;
      narr[4] = (arr[3] + arr[0] + arr[8])%mod;
      narr[5] = (arr[1] + arr[0] + arr[6])%mod;
      narr[6] = (arr[2] + arr[5])%mod;
      narr[7] = (arr[1] + arr[3])%mod;
      narr[8] = (arr[4] + arr[2])%mod;
      
      for(int i = 0 ; i < 9; i++) arr[i] = narr[i];
    }
    
    for(int i = 1 ; i < 9; i++) arr[0] = (arr[i] + arr[0])%mod;
    return arr[0];
  }
};