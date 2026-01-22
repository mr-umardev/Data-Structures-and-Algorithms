#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int removeDuplicates(vector<int>& arr, int n){
        int i=0;
        for(int j=1;j<n;++j){
            if(arr[j]!=arr[i]){
                ++i;
                arr[i]=arr[j];
            }
        }
        return i+1;
    }
};
int main(){
    vector<int>arr={1,1,2,2,2,3,3};
    int n=arr.size();
    Solution sol;
    int res1=sol.removeDuplicates(arr,n);
    cout<<res1;
    /*for(int num: res1){
        cout<<num<<" ";
    }*/
}
