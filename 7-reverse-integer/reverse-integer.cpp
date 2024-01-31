class Solution {
public:
    int reverse(int x) {
        int n=0,rem=0;     
        while(x){
         if (n>INT_MAX/10 || n<INT_MIN/10) 
         return 0; 
         rem=x%10;
         n=n*10+rem;
         x=x/10;  
        } 
        return n;  
    }
};    
    