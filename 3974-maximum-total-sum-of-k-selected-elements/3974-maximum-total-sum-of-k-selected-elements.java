class Solution {
    public long maxSum(int[] nums, int k, int mul) {
        Arrays.sort(nums);

        long ans=0;
        int n=nums.length;
        int j=n-1;
        while(k>0 && j>=0){
            if(mul!=0){
                ans=ans+1L*mul*nums[j];
                mul--;
            }
            else{
                ans=ans+nums[j];
            }
            j--;
            k--;
        }

        return ans;
    }
}