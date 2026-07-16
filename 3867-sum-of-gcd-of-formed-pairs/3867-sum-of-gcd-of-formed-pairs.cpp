class Solution {
public:

    int gcd(int a ,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {

        vector<int> prefixGcd;
        int maxi=-1e9;
        for(auto it:nums){
            maxi=max(maxi,it);

            prefixGcd.push_back(gcd(maxi,it));
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int n=prefixGcd.size();
        int i=0;
        int j=n-1;

        long long sum=0;
        while(i<j){
            sum=sum+gcd(prefixGcd[i],prefixGcd[j]);
            
            i++;
            j--;
        }

        return sum;
    }
};


// class Solution {
// public:

//     int gcd(int a, int b) {
//         if (b == 0) {
//             return a;
//         }
//         return gcd(b, a % b);
//     }
//     long long gcdSum(vector<int>& nums) {
//         vector<int> prefixGcd;
//         int maxi=-1e9;
//         for(int i=0;i<nums.size();i++){
//             maxi=max(nums[i],maxi);
//             prefixGcd.push_back(gcd(maxi,nums[i]));
//         }
//         sort(prefixGcd.begin(),prefixGcd.end());

//         for(auto it: prefixGcd){
//             cout<<it<<" ";
//         }

//         int i=0;
//         int j=prefixGcd.size()-1;

//         long long sum=0;
//         while(i<j){
//             sum=sum+gcd(prefixGcd[i],prefixGcd[j]);
//             i++;
//             j--;
//         }
//         return sum;
//     }
// };