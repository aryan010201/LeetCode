class Solution {
    public int numOfStrings(String[] patterns, String word) {
        HashSet<String> set=new HashSet<>();

        
        char[] arr=word.toCharArray();
        for(int i=0;i<word.length();i++){
            StringBuilder str=new StringBuilder("");
            for(int j=i;j<word.length();j++){
                str.append(arr[j]);
                set.add(str.toString());
            }
        }


        int c=0;



        for(String it:patterns){
            if(set.contains(it)){
                c++;
            }
        }
        return c;
        
    }
}