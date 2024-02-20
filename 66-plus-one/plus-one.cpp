class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int carry=1;
    int n=digits.size();
    for(int i=n-1;i>=0;i--){
        if(digits[i]!=9){
            digits[i]+=carry;
            carry=0;// no further carry after adding one
            break;
        }else{
            digits[i]=0;
        }
    }    
    if(digits[0]==0){
        digits.insert(digits.begin(),1);
    }
    return digits;
    }
};