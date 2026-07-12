class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long operation=1;
        long long currResources=k;
        const int inv2= 500000004;
        const int MOD=1e9+7;
        int ans=0;

        for(auto it:nums){
            if(it<=currResources){
                currResources-=it;
            }
            else{
                long long req=it-currResources;
                long long times=req%k==0?req/k:req/k+1;

                long long start=operation;
                long long end=(operation+times-1);
                long long n=end-start+1;

                long long a=((start%MOD+end%MOD)%MOD*n%MOD)%MOD;
                a=a*inv2%MOD;
                ans=(ans+a)%MOD;

                currResources=currResources*1LL+k*times*1LL-it;
                operation+=times*1L;
            }
        }
        return ans;
        
    }
};