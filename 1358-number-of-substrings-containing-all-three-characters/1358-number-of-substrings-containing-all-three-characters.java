class Solution {
    public int numberOfSubstrings(String s) {
        int i=0;
        int  n=s.length();
        int j=0;
        char[] arr=s.toCharArray();
        HashMap<Character,Integer> mp=new HashMap<>();
        int ans=0;
        while(j<n){
            mp.put(arr[j],mp.getOrDefault(arr[j],0)+1);
            while(mp.size()==3){
                ans=ans+n-j;
                mp.put(arr[i],mp.get(arr[i])-1);
                if(mp.get(arr[i])==0){
                    mp.remove(arr[i]);
                }
                i++;
            }
            
            j++;
        }
        return ans;
    }
}