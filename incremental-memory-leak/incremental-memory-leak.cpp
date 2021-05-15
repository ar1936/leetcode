class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i=1;
        // vector<int>v;
        while(memory1>0||memory2>0){
            if(memory2>memory1)
                memory2-=i;
            else
                memory1-=i;
            if(memory1<0||memory2<0)
            {
                if(memory1<0)
                    memory1+=i;
                else
                    memory2+=i;
                // i--;
                
                break;
            }

             i++;
        }
        return {i,memory1,memory2};
    }
};