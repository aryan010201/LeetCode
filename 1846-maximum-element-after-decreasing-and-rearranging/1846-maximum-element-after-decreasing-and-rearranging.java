class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        int n=arr.length;
        int prev=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]>(prev+1)){
                arr[i]=prev+1;
            }
            prev=arr[i];
        }
        return arr[n-1];
        
    }
}