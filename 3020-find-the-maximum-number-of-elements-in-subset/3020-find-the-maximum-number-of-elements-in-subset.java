class Solution {
    public int maximumLength(int[] nums) {
        // the frequency of elements present in subset should be greater than or equal to 2
        HashSet<Integer> st=new HashSet<>();
        HashMap<Integer,Integer> mp=new HashMap<>();
        int ones=0;
        for(int it:nums){
            st.add(it);
            mp.put(it, mp.getOrDefault(it, 0) + 1);
            if(it==1){
                ones++;
            }
            
        }

        int ans=1;
        for(Integer it:st){
            int num=it;
            if(num!=1 && mp.get(num)>=2){
                int len=2;
                while(num<(int)1e9/num && st.contains(num*num)){
                    if(mp.get(num*num)>=2){
                        len=len+2;
                    }
                    else if(mp.get(num*num)==1){
                        len=len+1;
                        break;
                    }
                   
                    num=num*num;
                }
                ans=Math.max(ans,len);
            }
        }
        if(ans%2==0){
            ans--;
        }
        if(ones%2==0){
            ones--;
        }

        return Math.max(ans,ones);
    }
}