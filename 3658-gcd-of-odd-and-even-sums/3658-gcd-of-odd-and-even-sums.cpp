class Solution {
public:


    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
       int oddFirst=1;
       int evenFirst=2;
       int oddLast=1+(n-1)*2;
       int evenLast=2+(n-1)*2;


       int oddSum=n*(1+oddLast)/2;
       int evenSum=n*(2+evenLast)/2;

       cout<<oddSum<<" "<<evenSum;

       return gcd(oddSum,evenSum);
       
        
    }
};