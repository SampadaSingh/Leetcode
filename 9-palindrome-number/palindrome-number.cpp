class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0 || (x!=0 && x%10==0)){
          return false;
      } 
      long int rev=0,ini=x; 
      while(x>0){
          rev=rev*10+x%10;
          x=x/10;
      }
       return ini==rev;
    }
};