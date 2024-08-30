class Solution {
public:
    bool isPalindrome(int x) {
        int n,   temp=0;
        long rev=0;
        n=x;
         n= abs(n);
        while(x!=0){
        temp=x%10;
        rev=(rev*10)+temp;
        x=x/10;
        }
        if(n<0){
            rev=rev*-1;
        }
        if(n==rev){
            return 1;
        }
        else{
            return 0;
        }

    }
};