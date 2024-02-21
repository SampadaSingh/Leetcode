class Solution {
public:
    string addBinary(string a, string b) {
    int carry=0; 
    int i=a.length()-1;
    int j=b.length()-1;
    string result="";
     while (i >= 0 || j >= 0 || carry != 0) {//loop until no carry is left
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';//converting character to integer
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';//converting character to integer
                j--;
            }
            result = to_string(sum % 2) + result;
            carry = sum / 2;// update carry for the next iteration
     }
    return result;
    }
};