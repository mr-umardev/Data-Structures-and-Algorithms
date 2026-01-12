#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool Armstrong(int n){
        int total=0,originalnum=n;
        while(n>0){
            int digit=n%10;
            total+=pow(digit,3);
            n=n/10;
        }
        if(total==originalnum){
            return true;
        }
        return false;
    }
};
int main(){
    int n=153;
    Solution sol;
    bool res1=sol.Armstrong(n);
    cout<<res1;
}
